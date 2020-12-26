#ifndef _UBW_H_
#define _UWB_H_

#include <iostream>
#include <string.h>
#include "common.h"
using namespace std;

bool ReadUwbData(string path, UwbData &Uwb, UwbData &weight);

bool LS(vector<double> data, vector<double> weight, Vector2d* ref, Point &result);
#endif
