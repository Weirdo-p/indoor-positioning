#include "../include/datareader.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

bool ReadWifiData(string path, GridPoint &gp){
    ifstream in(path);
    if(!in)
        return false;

    GridPoint tmp;
    while (!in.eof()){
        string line, mac, name;
        int time, rss = 0;
        stringstream buff;
        getline(in, line);
        // 去标点
        replace(line.begin(), line.end(), ',', ' ');
        replace(line.begin(), line.end(), '.', '0');
        buff << line;
        buff >> time >> mac >> rss >> name;
        // cout << mac << endl;
        if(mac == "")
            continue;
            if(gp[mac] > 0)
                cout << "tev" << endl;
        if(gp.find(mac) == gp.end()){
            gp[mac] = rss;
            tmp[mac] = 1;
        }
        else{
            gp[mac] += rss;
            tmp[mac] ++;
        }
    }
    for(GridPoint::iterator iter = gp.begin(); iter != gp.end(); ++ iter)
        gp[iter->first] /= double(tmp[iter->first]); 
}