main:
	mkdir -p build
	g++ -o build/main -std=c++17 -g ./src/*.cpp
	./build/main > image.ppm
	open image.ppm