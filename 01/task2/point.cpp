#include <iostream>
#include "point.h"
#include <cmath>


void Point::setCoordinates() {
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
}

void Point::getCoordinates() {
    std::cout << "x: " << x << "y: " << y << '\n';
}

double Point::distanceToCenter() {
    return sqrt(x*x + y*y);
}

double Point::distanceTo(const Point &OtherPoint) {
    return sqrt((x-OtherPoint.x)*(x-OtherPoint.x) + (y-OtherPoint.y)*(y-OtherPoint.y));
}