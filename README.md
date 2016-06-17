# Fractastic
Fractastic is a simple and approachable fractal generator written in C. It generates Julia set fractals by repeatedly iterating a complex quadratic function until divergence (or convergence). The number of iterations required to diverge at a point is recorded and used as part of the value to color the related pixel in the final, rendered image of the fractal.

## Usage
`run.sh` is a script that will handle everything for you automatically. It is heavily commented, so you can see the exact steps that it takes. The C program outputs to `stdout`; `run.sh` just captures its output and pipes it to a `ppm` (and `png`, if ImageMagick is installed) file.

Use `run.sh` as follows:
```
./run.sh [output_file] [fractastic_options]
```

where [fractastic_options] are the options that you would pass in as if you had invoked `fractastic` directly (as follows).

For Julia sets:
```
./fractastic J [width] [height]
               [x_min] [x_max] [y_min] [y_max]
               [max_iterations]
               [color_multiplier]
               [c_re] [c_im]
               [d]
```

And for Mandelbrot sets:
```
./fractastic M [width] [height]
               [x_min] [x_max] [y_min] [y_max]
               [max_iterations]
               [color_multiplier]
               [d]
```

### Parameter Descriptions

* `output_file`: the name of the file to output to (do not include file extension; `.ppm` and `.png` are auto-generated)
* `width`: the width of the output file in pixels
* `height`: the height of the output file in pixels
* `x_min`: the *x*-coordinate of the left bound of the rendered image (left bound of the window)
* `x_max`: the *x*-coordinate of the right bound of the rendered image (right bound of the window)
* `y_min`: the *y*-coordinate of the lower bound of the rendered image (lower bound of the window)
* `y_max`: the *y*-coordinate of the upper bound of the rendered image (upper bound of the window)
* `max_iterations`: the number of iterations to try before determining that f does not diverge
* `color_multiplier`: a multiplier for the contrast of the image (lower values result in more black; higher values result in more white; honestly, just play with it until the fractal looks nice!)
* `c_re`: the real component of the complex parameter `c` to be passed into the iterated function *f(z) = z<sup>d</sup> + c*
* `c_im`: the imaginary component of the complex parameter `c` to be passed into the iterated function *f(z) = z<sup>d</sup> + c*
* `d`: the real parameter `d` to be passed into the iterated function *f(z) = z<sup>d</sup> + c*

Note that the scale and step of the render algorithm are automatically determined from the above parameters.

### ImageMagick
ImageMagick is available in most package managers, including `homebrew` (Mac) and `apt-get` (Debian, Ubuntu, etc.). Just install it, and be sure that the `convert` command is available. If you do not install ImageMagick, `fractastic` will still work, but you will not be able to get `png` output (only `ppm`).

## Examples

To generate all of these examples, execute `./gen-examples.sh`. Note that this may take a while depending on the speed of your computer.

I deleted the `ppm` output of these commands before uploading them to the git repository to save (massive amounts) of space. In normal usage, these commands will generate `ppm` files.

### Example 1 (Julia Set)

#### Input

*f(z) = z<sup>2</sup> - 0.618*

```
./run.sh examples/julia1 J 2000 2000 -2 2 -2 2 1000 20 -0.618 0 2
```

#### Output

![Julia Set Fractal 1](/examples/julia1.png?raw=true "Julia Set Fractal 1")

### Example 2 (Julia Set)

#### Input

*f(z) = z<sup>2</sup> + (-0.4 + 0.6i)*

```
./run.sh examples/julia2 J 2000 2000 -2 2 -2 2 1000 1 -0.4 0.6 2
```

#### Output

![Julia Set Fractal 2](/examples/julia2.png?raw=true "Julia Set Fractal 2")

### Example 3 (Julia Set)

#### Input

*f(z) = z<sup>3</sup> + (-0.4 + 0.6i)*

```
./run.sh examples/julia3 J 2000 2000 -2 2 -2 2 1000 1 -0.4 0.6 3
```

#### Output

![Julia Set Fractal 3](/examples/julia3.png?raw=true "Julia Set Fractal 3")

### Example 4 (Julia Set)

#### Input

*f(z) = z<sup>2</sup> + (-0.8 + 0.156i)*

```
./run.sh examples/julia4 J 2000 2000 -2 2 -2 2 1000 1 -0.8 0.156 2
```

#### Output

![Julia Set Fractal 4](/examples/julia4.png?raw=true "Julia Set Fractal 4")

### Example 5 (Mandelbrot Set)

#### Input

*f(z) = z<sup>2</sup> + c*

```
./run.sh examples/mandel1 M 2000 2000 -2.5 1.5 -2 2 1000 1 2
```

#### Output

![Mandelbrot Set Fractal 1](/examples/mandel1.png?raw=true "Mandelbrot Set Fractal 1")

### Example 6 (Mandelbrot Set)

#### Input

*f(z) = z<sup>3</sup> + c*

```
./run.sh examples/mandel2 M 2000 2000 -2 2 -2 2 1000 1 3
```

#### Output

![Mandelbrot Set Fractal 2](/examples/mandel2.png?raw=true "Mandelbrot Set Fractal 2")

### Example 7 (Mandelbrot Set)

#### Input

*f(z) = z<sup>4</sup> + c*

```
./run.sh examples/mandel3 M 2000 2000 -2 2 -2 2 1000 1 4
```

#### Output

![Mandelbrot Set Fractal 3](/examples/mandel3.png?raw=true "Mandelbrot Set Fractal 3")

## Purpose

The purpose of this project was to create a simple yet powerful fractal generator in pure, best-practice C code without relying on external libraries. This was done so that I could learn more about fractals and C, as well as to serve as a pedagogical tool for other beginners to learn about C (in particular, how to generate images). Most of the resources I found online were in incomprehensible, difficult-to-read C or used advanced graphics libraries, so I wanted to provide an alternative.

## Possible Improvements

* Color
