# Fractastic
Fractastic is a fractal generator written in C.

## Usage
`run.sh` is a script that will handle everything for you automatically. It is heavily commented, so you can see the exact steps that it takes. The C program outputs to `stdout`; `run.sh` just captures its output and pipes it to a `ppm` (and `png`, if ImageMagick is installed) file.

Use `run.sh` as follows:
```
./run.sh [outputFile] [width] [height] [x_min] [x_max] [y_min] [y_max] [c_re] [c_im] [color_multiplier]
```

### ImageMagick
ImageMagick is available in most package managers, including `homebrew` (Mac) and `apt-get` (Debian, Ubuntu, etc.). Just install it, and be sure that the `convert` command is available.
