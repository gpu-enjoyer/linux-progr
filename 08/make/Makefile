
MAKEFLAGS += -s

all: build run

build:
	rm -rf .build
	mkdir .build
	g++ main.cc -o .build/main

run:
	./.build/main
