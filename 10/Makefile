MAKEFLAGS += -s

all: build run check

install:
	sudo apt install valgrind
# valgrind
#   - a suite of tools for debugging and profiling programs

build:
	rm -rf .build
	mkdir .build
	g++ file.cpp -o .build/file

run:
	./.build/file

check:
	valgrind --track-fds=yes ./.build/file
# check: is file-descriptor ok
