#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: ./run.sh [file] [fractastic_options]"
    exit 1
fi

# Create temporary file
tempFile=$(mktemp)

# Store output filename (arguments will be shifted later)
outputFile=$1

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
./fractastic $@ > $tempFile.ppm

# If there was an error with the program, exit
if [ $? -ne 0 ]; then
    rm $tempFile.ppm
    exit 3
fi

# Remove any previous image files with same name
if [ -f $outputFile.ppm  ]; then
    rm $outputFile.ppm
fi
if [ -f $outputFile.png  ]; then
    rm $outputFile.png
fi

# Move the temporary file to the output file
mv $tempFile.ppm $outputFile.ppm

# Convert the ppm to png, if possible
if [ "$(command -v convert)" ]; then
    convert $outputFile.ppm $outputFile.png
else
    echo "Install ImageMagick to get png output."
fi
