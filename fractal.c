#include <complex.h>

#include "fractal.h"

int divergence(double complex (*f)(const double complex, const double complex *const),
               const double complex z0,
               const double complex *const parameters,
               const double epsilon,
               const double infinity,
               const int max_iterations) {
    double complex z_old = z0;
    double complex z_new = f(z_old, parameters);

    for (int i = 0; i < max_iterations; i++) {
        z_old = z_new;
        z_new = f(z_old, parameters);

        if (cabs(z_new - z_old) < epsilon || cabs(z_new) > infinity) {
            return i;
        }
    }

    return 0;
}

double complex julia_c(const double complex z, const double complex *const parameters) {
    return z * z + parameters[0];
}
