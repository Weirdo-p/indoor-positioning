/******************************************************
 * this file declares some structures, const viaribles
 * @author XUZHUO WHU
 * 2020 10 25
******************************************************/
#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <Eigen/Core>
#include <Eigen/Dense>

extern const int ROW;
extern const int COL;

using namespace std;
using namespace Eigen;

typedef Eigen::Matrix<double, 8, 29> DataMap;
typedef map<string, double> GridPoint;
typedef map<string, DataMap> Grid;
typedef map<double, vector<double>> UwbData;

struct Point
{
    double X = -1;
    double Y = -1;

    Point(int x, int y) { X = x; Y = y; }
    friend ostream & operator<<(ostream &out, const Point p);
};

double dist(Vector2d v1, Vector2d v2);

#endif