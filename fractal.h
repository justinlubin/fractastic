#ifndef __FRACTAL_H__
#define __FRACTAL_H__

/*
 * Returns the number of iterations to convergence (including infinity). If the
 * function does not converge at the specified point, 0 is returned.
 *
 *              f: the function to iterate
 *             z0: the starting point
 *     parameters: the parameters to pass to f
 *        epsilon: how close a value has to get to an attractor before f can be
 *                 said to converge
 *       infinity: the value past which f is said to converge to infinity
 * max_iterations: the number of iterations to try before giving up and saying
 *                 f diverges
 */
int divergence(double complex (*f)(const double complex, const double complex *const),
               const double complex z0,
               const double complex *const parameters,
               const double epsilon,
               const double infinity,
               const int max_iterations);

/*
 * Returns a quadratic complex function evaluated at z paramaterized by the
 * complex variable c.
 *
 * parameters[0] = c
 *
 * Mathematically: f(z) = z^2 + c
 */
double complex julia_c(const double complex z, const double complex *const parameters);

#endif
