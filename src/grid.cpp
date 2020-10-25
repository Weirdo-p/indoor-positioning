#include "../include/grid.h"

const int PointNum = 232;

DataGrid::DataGrid(const Grid grid)
{
    this->gd = new GridPoint[PointNum];
    for(int i = 0; i < PointNum; ++i)
        gd[i] = grid[i];
}
