#include "../include/PiCalculation.h"

#include "../include/RandomPointGenerator.h"

PiCalculation::PiCalculation(int trials, double precision = 0.001) : trials(trials), precision(precision) {}

double PiCalculation::run() {
    RandomPointGenerator generator = RandomPointGenerator(precision);
    int totalPoints = 0;
    int pointsInsideCircle = 0;

    for (int i = 0; i < trials; i++) {
        auto [x, y] = generator.get_random_point();
        if (is_point_inside_circle(x, y)) pointsInsideCircle++;
        totalPoints++;
    }

    return 4.0 * pointsInsideCircle / totalPoints;
}

inline bool PiCalculation::is_point_inside_circle(double x, double y) {
    double dx = x - CIRCLE_CENTER_X;
    double dy = y - CIRCLE_CENTER_Y;
    return dx * dx + dy * dy <= CIRCLE_RADIUS * CIRCLE_RADIUS;
}