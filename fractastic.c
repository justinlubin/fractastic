#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <complex.h>

#include "ppm.h"
#include "fractal.h"

#define UNKNOWN_MODE 0
#define JULIA_MODE 1
#define MANDELBROT_MODE 2

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [J/M] [options]\n", argv[0]);
        return 1;
    } else {
        int mode = UNKNOWN_MODE;

        if (strcmp(argv[1], "J") == 0) {
            mode = JULIA_MODE;
        } else if (strcmp(argv[1], "M") == 0) {
            mode = MANDELBROT_MODE;
        }

        if (mode == UNKNOWN_MODE) {
            fprintf(stderr, "Unrecognized mode \"%s\"", argv[1]);
            return 2;
        } else if (mode == JULIA_MODE && argc != 13) {
            fprintf(stderr, "Usage: %s J [width] [height] [x_min] [x_max] [y_min] [y_max] [max_iterations] [color_multiplier] [c_re] [c_im] [d]\n", argv[0]);
            return 3;
        } else if (mode == MANDELBROT_MODE && argc != 11) {
            fprintf(stderr, "Usage: %s M [width] [height] [x_min] [x_max] [y_min] [y_max] [max_iterations] [color_multiplier] [d]\n", argv[0]);
            return 4;
        }

        int arg = 2;

        const int width = strtol(argv[arg++], NULL, 0);
        const int height = strtol(argv[arg++], NULL, 0);
        const double x_min = strtod(argv[arg++], NULL);
        const double x_max = strtod(argv[arg++], NULL);
        const double y_min = strtod(argv[arg++], NULL);
        const double y_max = strtod(argv[arg++], NULL);
        const int max_iterations = strtol(argv[arg++], NULL, 0);
        const int color_multiplier = strtol(argv[arg++], NULL, 0);

        const double c_re = mode == JULIA_MODE ? strtod(argv[arg++], NULL) : 0;
        const double c_im = mode == JULIA_MODE ? strtod(argv[arg++], NULL) : 0;
        const double d = strtod(argv[arg++], NULL);

        const double x_step = (x_max - x_min) / width;
        const double y_step = (y_max - y_min) / height;

        const fractal_config fc = {EPSILON, INFINITY, max_iterations};

        const double complex c = c_re + c_im * I;

        double complex parameters[2] = {c, d};

        double x0, y0;
        double complex z0;

        int iterations = 0, color = 0;

        output_color_header(width, height);

        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                x0 = x_min + col * x_step;
                y0 = y_max - row * y_step;
                z0 = x0 + y0 * I;

                if (mode == JULIA_MODE) {
                    iterations = julia(complex_polynomial,
                                       z0,
                                       parameters,
                                       &fc);
                } else if (mode == MANDELBROT_MODE) {
                    iterations = generalized_mandelbrot(complex_polynomial,
                                                        z0,
                                                        parameters,
                                                        0,
                                                        &fc);
                }

                if (iterations == CONVERGE) {
                    color = 255;
                } else {
                    color = color_multiplier * iterations;
                }

                output_color(color, color, color);
            }
            next_color_row();
        }

        return 0;
    }
}
