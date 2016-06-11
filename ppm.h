#ifndef __PPM_H__
#define __PPM_H__

/*
 * Outputs the PPM header for an ASCII color image of dimensions width x height.
 */

void output_color_header(const int width, const int height);

/*
 * Outputs a colored pixel.
 */
void output_color(const int r, const int g, const int b);

/*
 * Outputs a newline to go the next row of the PPM file.
 */
void next_color_row();

#endif
