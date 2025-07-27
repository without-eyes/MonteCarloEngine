#include "../include/PiCalculation.h"

#include "../include/RandomPointGenerator.h"

PiCalculation::PiCalculation(int trials, double precision = 0.001) : trials(trials), precision(precision) {}

double PiCalculation::run() {
    RandomPointGenerator generator = RandomPointGenerator(precision);
    int totalPoints = 0;
    int pointsInsideCircle = 0;

    for (int i = 0; i < trials; i++) {
        std::pair<double, double> point = generator.get_random_point();

        if (is_point_inside_circle(point.first, point.second, CIRCLE_CENTER_X, CIRCLE_CENTER_Y, CIRCLE_RADIUS)) {
            pointsInsideCircle++;
        }

        totalPoints++;
    }

    return 4.0 * pointsInsideCircle / totalPoints;
}

inline bool PiCalculation::is_point_inside_circle(double x, double y, double cx, double cy, double radius) {
    double dx = x - cx;
    double dy = y - cy;
    return dx * dx + dy * dy <= radius * radius;
}