#ifndef __FRACTAL_H__
#define __FRACTAL_H__

/*
 * The standard value for fractal_config.epsilon.
 */
#define EPSILON 0.01

/*
 * The standard value for fractal_config.infinity.
 */
#define INFINITY 2

/*
 * The value that represents a point that converges for a function.
 */
#define CONVERGE -1

/*
 * A struct for render configurations.
 *
 *        epsilon: unused (for now)
 *       infinity: the value past which f is said to converge to infinity
 * max_iterations: the number of iterations to try before determining that f
 *                 does not diverge
 */
typedef struct {
    double epsilon;
    double infinity;
    int max_iterations;
} fractal_config;

/*
 * A complex function that varies over z and is parameterized by the values of
 * "parameters".
 */
typedef double complex (*const complex_function)(const double complex z,
                                                 const double complex *const parameters);

/*
 * Determines whether or not a point z0 converges under iteration for a
 * function f with parameters.
 *
 * Returns the number of iterations until divergence, or the constant CONVERGE
 * if the point converges.
 */
int julia(complex_function f,
          const double complex z0,
          const double complex *const parameters,
          const fractal_config *const fc);

/*
 * Uses z0 as the k-th parameter for a function f.
 */
int generalized_mandelbrot(const complex_function f,
                           const double complex z0,
                           double complex *const parameters,
                           const int k,
                           const fractal_config *const fc);

/*
 * Returns f(z) = z^d + c evaluated at z0, where:
 *     parameters[0] = c
 *     parameters[1] = d
 */
double complex complex_polynomial(const double complex z0,
                                  const double complex *const parameters);

#endif
