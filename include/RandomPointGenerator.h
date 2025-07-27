#ifndef RANDOMPOINTGENERATOR_H
#define RANDOMPOINTGENERATOR_H

#include <random>
#include <utility>

class RandomPointGenerator {
public:
    RandomPointGenerator(double precision);

    std::pair<double, double> get_random_point();

private:
    double precision{};
    std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;
};

#endif //RANDOMPOINTGENERATOR_H
