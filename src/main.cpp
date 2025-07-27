#include <chrono>
#include <iostream>
#include <ostream>
#include "../include/MonteCarloEngine.h"
#include "../include/PiCalculation.h"

int main() {
    auto engine = MonteCarloEngine<PiCalculation>(10000, 0.001);

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

    double result = engine.run();

    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Result: " << result << std::endl;
    std::cout << "Time: " << duration << std::endl;
    return 0;
}
