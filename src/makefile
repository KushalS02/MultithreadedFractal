default: mandelbrotGen

all: clean mandelbrotGen

mandelbrotGen: mandelbrot.o
  gcc mandelbrot.o -o mandelbrotGen

mandelbrot.o: mandelbrot.c mandelbrot.h
  gcc -c mandelbrot.c

memMap.o: memMap.c memMap.h
  gcc -c memMap.c

clean:
  rm *.o mandelbrotGen
