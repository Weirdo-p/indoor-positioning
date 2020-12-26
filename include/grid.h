/************************************************************
 * this file declare grid generation's classes and functions
 * our data is 29 * 8, so I use a matrix to store it
 * @author XUZHUO
 * 2020 10 25
************************************************************/

#ifndef _GRID_H_
#define _GRID_H_

#include "common.h"

/***********************************************************
 * establish a dataset with STD::map
 * data structure is as follow:(MAC is KEY)
 *     MAC->Matrix->Data Point
 * input data is a one-dimensional dataset
 * in order to fill data into the matrix
 * I design a function to get its 2-dimensional position
 * if a point does not contain the data(KEY)
 * it will be set -1
 * @author XUZHUO WHU 2020 10 28
***********************************************************/
class DataGrid{
public:
    DataGrid(const GridPoint* grid);

    /*******************************************
     * function: to fill data in the map
     * @param posi [in]   position of the data
     * @param gp   [in]   data in this point
     * @param gd   [out]  new grid
     * @return  status code
    *******************************************/
    int fillin(int posi, GridPoint gp, Grid &gd);

    /*****************************************
     * function: get 2-dimensional position
     * @param posi 1-dimensional position
     * @return 2-dimensional position
    *****************************************/
    Point GetPosition(int posi);

public:
    /*******************************************
     * function: bilinear interpolation
     * @param posi      point number
     * @return status code
    *******************************************/
    int BiliInter(Point pt, string mac, Grid &gd);

    double CalculateCoeff(Point pt, Grid gd, GridPoint gp);

    double CalculateDist(Point pt, Grid gd, GridPoint gp);

    Point positioning(GridPoint gp);

private:
    Grid grid;
    float threshold;
};

#endif
