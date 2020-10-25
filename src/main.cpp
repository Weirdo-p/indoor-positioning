#include <iostream>
#include "../include/common.h"
#include "../include/datareader.h"
#include "../include/grid.h"

using namespace std;


int main(){
    string datapath = "/home/weirdo/Documents/coding/indoor-positioning/data/";
    string suffix = ".txt";
    Grid grid = new GridPoint[PointNum];
    for(int i = 0; i < PointNum; ++i){
        string data = datapath + to_string(i) + suffix;
        GridPoint gp;
        bool flag = ReadWifiData(data, gp);
        if(flag)
            grid[i] = gp;
    }
    DataGrid wifiGird(grid);
    delete [] grid;
    for(int i = 0; i < PointNum; ++i){
        if(wifiGird.gd[i].size() == 0)
            cout << "no member" << endl;
        for(GridPoint::iterator iter = wifiGird.gd[i].begin(); iter != wifiGird.gd[i].end(); ++iter){
            cout << wifiGird.gd[i][iter->first] << endl;
        }
        cout << endl;
    }
    return 0;
}