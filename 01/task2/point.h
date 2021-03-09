#ifndef POINT_H
#define POINT_H

struct Point {
    private:
    double x;
    double y;

    public:

    void setCoordinates();

    void getCoordinates();

    double distanceToCenter();

    double distanceTo(const Point &OtherPoint);
};
#endif