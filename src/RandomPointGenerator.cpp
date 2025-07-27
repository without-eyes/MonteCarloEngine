#include "../include/RandomPointGenerator.h"

RandomPointGenerator::RandomPointGenerator(double precision) : precision(precision), rng(dev()), dist(0, static_cast<int>(1.0 / precision)) {}

std::pair<double, double> RandomPointGenerator::get_random_point() {
    double x = dist(rng) * precision;
    double y = dist(rng) * precision;
    return std::make_pair(x, y);
}