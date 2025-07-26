#include "../include/PiCalculation.h"

PiCalculation::PiCalculation(int trials, double precision) : trials(trials), precision(precision), rng(dev()), dist(0, static_cast<int>(1.0 / precision)) {}

double PiCalculation::run() {
    int totalPoints = 0;
    int pointsInsideCircle = 0;

    for (int i = 0; i < trials; i++) {
        std::pair<double, double> point = get_random_point();

        if (is_point_inside_circle(point.first, point.second, CIRCLE_CENTER_X, CIRCLE_CENTER_Y, CIRCLE_RADIUS)) {
            pointsInsideCircle++;
        }

        totalPoints++;
    }

    return 4.0 * pointsInsideCircle / totalPoints;
}

bool PiCalculation::is_point_inside_circle(double x, double y, double cx, double cy, double radius) {
    double dx = x - cx;
    double dy = y - cy;
    return dx * dx + dy * dy <= radius * radius;
}

std::pair<double, double> PiCalculation::get_random_point() {
    double x = dist(rng) * precision;
    double y = dist(rng) * precision;
    return std::make_pair(x, y);
}
