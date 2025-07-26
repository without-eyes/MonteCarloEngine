#include "../include/MonteCarloEngine.h"

template <typename Experiment>
MonteCarloEngine<Experiment>::MonteCarloEngine(uint64_t trials) : trials(trials) {}

template <typename Experiment>
double MonteCarloEngine<Experiment>::run(Experiment &experiment) {
    double result = 0;
    for (uint64_t i = 0; i < trials; i++) {
        result += experiment->run();
    }
    return result / trials;
}