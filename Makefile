CC = gcc

CFLAGS = -g -Wall -O3
LDFLAGS = -g -lm

fractastic: ppm.o fractal.o fractastic.o

fractastic.o: fractastic.c
fractastic.c: ppm.h fractal.h

ppm.o: ppm.c
ppm.c: ppm.h

fractal.o: fractal.c
fractal.c: fractal.h

.PHONY: clean
clean:
	rm -f *.o fractastic

.PHONY: all
	all: clean fractastic
