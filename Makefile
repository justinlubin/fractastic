CC = gcc

CFLAGS = -g -Wall -O3
LDFLAGS = -g -lm

fractal-generator: ppm.o fractal.o fractal-generator.o

fractal-generator.o: fractal-generator.c
fractal-generator.c: ppm.h fractal.h

ppm.o: ppm.c
ppm.c: ppm.h

fractal.o: fractal.c
fractal.c: fractal.h

.PHONY: clean
clean:
	rm -f *.o fractal-generator

.PHONY: all
	all: clean fractal-generator
