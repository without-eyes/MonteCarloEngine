#include <chrono>
#include <iostream>
#include <ostream>
#include "../include/MonteCarloEngine.h"
#include "../include/PiCalculation.h"

int main() {
    auto piCalculation = PiCalculation(10000, 0.01);
    auto engine = MonteCarloEngine<PiCalculation>(10000);

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

    double result = engine.run(piCalculation);

    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Result: " << result << std::endl;
    std::cout << "Time: " << duration << std::endl;
    return 0;
}
