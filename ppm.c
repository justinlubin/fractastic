#include <stdio.h>

#include "ppm.h"

void output_color_header(const int width, const int height) {
    printf("P3 %d %d 255\n", width, height);
}

void output_color(const int r, const int g, const int b) {
    printf("%d %d %d ", r, g, b);
}

void next_color_row() {
    printf("\n");
}
