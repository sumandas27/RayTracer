SRCDIR = ./src
SRCS := $(shell find $(SRCDIR) -name '*.cpp')

main:
	mkdir -p build
	g++ -o build/main -std=c++17 -g -O $(SRCS)
	build/main > image.ppm
	open image.ppm

debug:
	mkdir -p build
	g++ -o build/main -std=c++17 -g $(SRCS)
	./build/main