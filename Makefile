INCLUDES = $(-I${workspaceFolder}/src/)
SRCDIR = src
SRCS := $(shell find $(SRCDIR) -name '*.cpp')

# ./build/main > image.ppm
# open image.ppm

main:
	mkdir -p build
	g++ $(SRCS) -o build/main -std=c++17 -g *.cpp
	./build/main > image.ppm
	open image.ppm