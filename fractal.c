#include <complex.h>

#include "fractal.h"

int julia(const complex_function f,
          const double complex z0,
          const double complex *const parameters,
          const fractal_config *const fc) {
    double complex z_old = z0;
    double complex z_new = f(z_old, parameters);

    for (int i = 1; i < fc->max_iterations; i++) {
        z_old = z_new;
        z_new = f(z_old, parameters);

        if (cabs(z_new) > fc->infinity) {
            return i;
        }
    }

    return CONVERGE;
}

int generalized_mandelbrot(const complex_function f,
                           const double complex z0,
                           double complex *const parameters,
                           const int k,
                           const fractal_config *const fc) {
    parameters[k] = z0;
    return julia(f, 0, parameters, fc);
}

double complex complex_polynomial(const double complex z0,
                                  const double complex *const parameters) {
    const double complex c = parameters[0];
    const double complex d = parameters[1];
    return cpow(z0, d) + c;
}
