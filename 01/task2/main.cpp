#include <iostream>
#include "point.h"


int main() {
    Point p1, p2;

    p1.setCoordinates();
    p2.setCoordinates();
    std::cout << "P1 distance to center " << p1.distanceToCenter() << '\n';
    std::cout << "P2 distance to center " << p2.distanceToCenter() << '\n';
    std::cout << "P1 distance to P2 " << p1.distanceTo(p2) << '\n';

    return 0;
}