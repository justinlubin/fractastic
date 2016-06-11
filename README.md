# Fractastic
Fractastic is a fractal generator written in C.

## Usage
`run.sh` is a script that will handle everything for you automatically. It is heavily commented, so you can see the exact steps that it takes. The C program outputs to `stdout`; `run.sh` just captures its output and pipes it to a `ppm` (and `png`, if ImageMagick is installed) file.

Use `run.sh` as follows:
```
./run.sh [outputFile] [width] [height] [x_min] [x_max] [y_min] [y_max] [c_re] [c_im] [color_multiplier]
```

And, if you wish, you can invoke `fractastic` directly:
```
./fractastic [width] [height] [x_min] [x_max] [y_min] [y_max] [c_re] [c_im] [color_multiplier]
```

The only difference in the parameters is that `run.sh` takes an `outputFile` whereas `fractastic` does not.

### Parameter Descriptions

* `outputFile`: the name of the file to output to (do not include file extension; `.ppm` and `.png` are auto-generated)
* `width`: the width of the output file in pixels
* `height`: the height of the output file in pixels
* `x_min`: the *x*-coordinate of the left bound of the rendered image (left bound of the window)
* `x_max`: the *x*-coordinate of the right bound of the rendered image (right bound of the window)
* `y_min`: the *y*-coordinate of the lower bound of the rendered image (lower bound of the window)
* `y_max`: the *y*-coordinate of the upper bound of the rendered image (upper bound of the window)
* `c_re`: the real component of the complex parameter `c` to be passed into the iterated function f(z) = z<sup>2</sup> + c
* `c_im`: the imaginary component of the complex parameter `c` to be passed into the iterated function f(z) = z<sup>2</sup> + c
* `color_multiplier`: a multiplier for the contrast of the image (lower values result in more black; higher values result in more white; honestly, just play with it until the fractal looks nice!)

Note that the scale and step of the render algorithm are automatically determined from the above parameters.

### ImageMagick
ImageMagick is available in most package managers, including `homebrew` (Mac) and `apt-get` (Debian, Ubuntu, etc.). Just install it, and be sure that the `convert` command is available.

## Examples

Example 1:
```
./run.sh examples/fractal1 1000 1000 -2 2 -2 2 -0.618 0 20
```
Output for Example 1:

![Fractal 1](/examples/fractal1.png?raw=true "Fractal 1")

Example 2:
```
./run.sh examples/fractal2 1000 1000 -2 2 -2 2 -0.4 0.6 1
```
Output for Example 2:

![Fractal 2](/examples/fractal2.png?raw=true "Fractal 2")

Example 3:
```
./run.sh examples/fractal3 1000 1000 -2 2 -2 2 -0.8 0.156 1
```
Output for Example 3:

![Fractal 3](/examples/fractal3.png?raw=true "Fractal 3")
