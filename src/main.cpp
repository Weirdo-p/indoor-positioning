#include <iostream>
#include "../include/common.h"
#include "../include/datareader.h"
#include "../include/grid.h"
#include "../include/uwb.h"
#include "Eigen/Core"

using namespace std;

int main() {
    //////////////////////////////////////////////////////////////////////////////////////////////
    //  UWB  //
    // UwbData data, weight;
    // // // 基准站
    // Vector2d ref[4];
    // ref[0] << 0, 0;
    // ref[1] << 3.0, 0;
    // ref[2] << 3.0, 3.6;
    // ref[3] << 0, 3.6;
    
    // string uwbpath = "/home/weirdo/Documents/code/C++/indoor-positioning/wifi_uwb/data/UWB/UWBDATA.txt";
    // ReadUwbData(uwbpath, data, weight);
    // for(UwbData::iterator iter = data.begin(); iter != data.end(); ++iter) {
    //         Point result(0, 0);
    //         LS(data[iter->first], weight[iter->first], ref, result);
    // }

    //////////////////////////////////////////////////////////////////////////////////////////////
    //  WIFI  //
    string datapath = "/home/weirdo/Documents/code/C++/indoor-positioning/wifi_uwb/data/";
    string suffix = ".txt";
    GridPoint* pt = new GridPoint[ROW * COL];
    for(int i = 0; i < ROW * COL; ++i) {
        string data = datapath + to_string(i) + suffix;
        GridPoint gp;
        bool flag = ReadWifiData(data, gp);
        if(flag)
            pt[i] = gp;
    }

    // for(auto gp : )
    DataGrid wifiGird(pt);
    delete[] pt;

    GridPoint* test = new GridPoint[10];
    for(int i = 1000; i < 1010; ++i) {
        string data = datapath + to_string(i) + suffix;
        GridPoint gp;
        bool flag = ReadWifiData(data, gp);
        if(flag)
            test[i - 1000] = gp;
    }
    for(int i = 0; i < 9; ++i)
        wifiGird.positioning(test[i]);
    // cout << wifiGird.GetPosition(231 - 28) << endl;
    delete[] test;
    return 0;
    
}