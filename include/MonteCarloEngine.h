#ifndef MONTECARLOENGINE_H
#define MONTECARLOENGINE_H
#include <cstdint>


template <typename Experiment>
class MonteCarloEngine {
public:
    explicit MonteCarloEngine(uint64_t trials);

    double run(Experiment& experiment);

private:
    uint64_t trials;
};

#endif //MONTECARLOENGINE_H