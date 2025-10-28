MAKEFLAGS += -s

all: build run

build:
	rm -rf .build
	mkdir .build
	g++ file.cpp -o .build/file

run:
	./.build/file
