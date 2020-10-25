/******************************************
 * this file declares read data functions
 * @author XUZHUO WHU
 * 2020 10 25
******************************************/
#ifndef _DATAREADER_H_
#define _DATAREADER_H_

#include "common.h"
#include <iostream>
using namespace std;

/******************************************
 * function: read wifi data from files
 * file fomat: time,mac,rssi,ap
 * @param path [in]    file path
 * @param gp   [out]   grid point
 * @return status code
******************************************/
bool ReadWifiData(string path, GridPoint &gp);

#endif