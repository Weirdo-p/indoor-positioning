#include "../include/common.h"
#include <iostream>
using namespace std;

ostream & operator<<(ostream &out, const Point p)
{
    out << p.X << "  " << p.Y;
}

double dist(Vector2d v1, Vector2d v2) {
    double x2 = pow(v1(0, 0) - v2(0, 0), 2);
    double y2 = pow(v1(1, 0) - v2(1, 0), 2);
    return sqrt(x2 + y2);
}

