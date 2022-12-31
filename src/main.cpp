#include "RayTracer.hpp"
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    RayTracer rt = RayTracer();
    rt.output_image();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cerr << "EXECUTION TIME - " << duration.count() << "ms\n";
    return 0;
}