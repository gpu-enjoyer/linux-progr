
MAKEFLAGS += -s

all: build run

install:
	sudo apt install pkg-config

build:
	rm -rf .build
	mkdir .build
# 	g++ main.cc -o .build/main
	$(CXX) main.cc -o .build/main $(shell pkg-config --cflags --libs zlib)

run:
	./.build/main
