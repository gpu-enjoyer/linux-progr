
all: build run

build:
	rm -rf .build
	mkdir .build
	gcc code/Mandelbrot.c code/framebuffer.c -o .build/Mandelbrot

run:
	sudo .build/Mandelbrot
