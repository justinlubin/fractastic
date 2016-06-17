#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: ./run.sh [output_file] [fractastic_options]"
    exit 1
fi

# Create temporary file
temp_file=$(mktemp)

# Store output filename (arguments will be shifted later)
output_file=$1

# Compile the program
make

# If there was an error with compilation, exit
if [ $? -ne 0 ]; then
    exit 2
fi

# Shift the arguments so that the output filename does not get
# passed to the C program
shift

# Run the program and save the output to a temporary PPM file
./fractastic $@ > $temp_file.ppm

# If there was an error with the program, exit
if [ $? -ne 0 ]; then
    rm $temp_file.ppm
    exit 3
fi

# Remove any previous image files with same name
if [ -f $output_file.ppm  ]; then
    rm $output_file.ppm
fi
if [ -f $output_file.png  ]; then
    rm $output_file.png
fi

# Move the temporary file to the output file
mv $temp_file.ppm $output_file.ppm

# Convert the ppm to png, if possible
if [ "$(command -v convert)" ]; then
    convert $output_file.ppm $output_file.png
else
    echo "Install ImageMagick to get png output."
fi
