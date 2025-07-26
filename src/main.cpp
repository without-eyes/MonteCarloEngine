#include <iostream>
#include <ostream>
#include "../include/MonteCarloEngine.h"
#include "../include/PiCalculation.h"

int main() {
    auto piCalculation = PiCalculation(10000, 0.01);
    auto engine = MonteCarloEngine<PiCalculation>(10000);
    double result = engine.run(piCalculation);
    std::cout << result << std::endl;
    return 0;
}
