
MAKEFLAGS += -s

all: build run

build:
	rm -rf .build
	mkdir .build
	g++ -DUSE_GPU -DUSE_FLOAT macro.cpp -o .build/macro

run:
	.build/macro && echo " --------- done ------- "
