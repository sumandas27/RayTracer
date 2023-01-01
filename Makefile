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

cloc:
	git clone --depth 1 https://github.com/sumandas27/RayTracer.git
	cloc RayTracer --fullpath --not-match-d="(src/dependencies)" --not-match-f="(Makefile)" --exclude-ext=json,plist
	rm -rf RayTracer