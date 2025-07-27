#ifndef PICALCULATION_H
#define PICALCULATION_H

#define CIRCLE_CENTER_X 0.5
#define CIRCLE_CENTER_Y 0.5
#define CIRCLE_RADIUS 0.5

class PiCalculation {
public:
    PiCalculation(int trials, double precision);

    double run();

private:
    int trials;
    double precision;

    bool is_point_inside_circle(double x, double y);
};

#endif //PICALCULATION_H
