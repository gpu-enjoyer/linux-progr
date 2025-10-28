
MAKEFLAGS += -s

all: build run

build:
	rm -rf .build
	mkdir .build
	gcc main.c -o .build/main

run:
	./.build/main
