#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

#include "ppm.h"
#include "fractal.h"

int main(int argc, char **argv) {
    if (argc != 13) {
        fprintf(stderr, "[ERROR] Correct usage: %s [width] [height] [x_min] [x_max] [y_min] [y_max] [c_re] [c_im] [epsilon] [infinity] [max_iterations] [color_multiplier]\n", argv[0]);
        return 1;
    }

    const int width = strtol(argv[1], NULL, 0);
    const int height = strtol(argv[2], NULL, 0);

    const double x_min = strtod(argv[3], NULL);
    const double x_max = strtod(argv[4], NULL);
    const double y_min = strtod(argv[5], NULL);
    const double y_max = strtod(argv[6], NULL);

    const double c_re = strtod(argv[7], NULL);
    const double c_im = strtod(argv[8], NULL);

    const double epsilon = strtod(argv[9], NULL);
    const double infinity = strtod(argv[10], NULL);

    const int max_iterations = strtol(argv[11], NULL, 0);

    const int color_multiplier = strtol(argv[12], NULL, 0);

    const double x_step = (x_max - x_min) / width;
    const double y_step = (y_max - y_min) / height;

    const double complex c = c_re + c_im * I;

    const double complex parameters[] = {c};

    double x0, y0;
    double complex z0;

    int iterations, color;

    output_color_header(width, height);

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            x0 = x_min + col * x_step;
            y0 = y_max - row * y_step;
            z0 = x0 + y0 * I;

            iterations = divergence(julia_c, z0, parameters, epsilon, infinity, max_iterations);
            color = color_multiplier * iterations;

            output_color(color, color, color);
        }
        next_color_row();
    }

    return 0;
}
