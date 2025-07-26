#ifndef MONTECARLOENGINE_H
#define MONTECARLOENGINE_H

#include <cstdint>

template <typename Experiment>
class MonteCarloEngine {
public:
    explicit MonteCarloEngine(uint64_t trials) : trials(trials) {}

    double run(Experiment& experiment) {
        double result = 0;
        for (uint64_t i = 0; i < trials; i++) {
            result += experiment.run();
        }
        return result / trials;
    }

private:
    uint64_t trials;
};

#endif //MONTECARLOENGINE_H