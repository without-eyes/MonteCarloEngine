#ifndef PICALCULATION_H
#define PICALCULATION_H

#include <utility>
#include <random>

#define CIRCLE_CENTER_X 0.5
#define CIRCLE_CENTER_Y 0.5
#define CIRCLE_RADIUS 0.5

class PiCalculation {
public:
    PiCalculation(int trials, double precision = 0.01);

    double run();

private:
    int trials;
    double precision;
    std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;

    bool is_point_inside_circle(double x, double y, double cx, double cy, double radius);

    std::pair<double, double> get_random_point();
};

#endif //PICALCULATION_H
