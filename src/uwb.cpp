#include "../include/uwb.h"
#include "../include/common.h"
#include <fstream>
#include <sstream>

bool ReadUwbData(string path, UwbData &data, UwbData &weight) {
    ifstream in(path);
    if(!in) {
        cout << "open error" << endl;
        return false;
    }

    while(!in.eof()) {
        string line;
        getline(in, line);
        if(line[0] == 'p') {
            // stringstream tmp;
            int pointnum =  int(line[5]) - 48; // ascii code
            while (!in.eof())
            {
                getline(in, line);
                if(line.substr(0, 4) == "   M") {
                    string da = line.substr(26, 7);
                    stringstream tmp;
                    tmp << da;
                    double dist;
                    tmp >> dist;
                    data[pointnum].push_back(dist / 1000.0);
                    // break;
                }
                if(line.substr(0, 9) == "   StdDev") {
                    string da = line.substr(26, 7);
                    stringstream tmp;
                    tmp << da;
                    double w;
                    tmp >> w;
                    weight[pointnum].push_back(w / 1000.0);
                    break;
                }
            }
            
        }
    }
    return 0;
}

bool LS(vector<double> obs, vector<double> weight, Vector2d* ref, Point &result) {
    Vector2d station(0.01, 0.01);

    MatrixXd B(obs.size(), 2);
    MatrixXd P(obs.size(), obs.size());
    // P = MatrixXd::Zero();
    MatrixXd l(obs.size(), 1);
    Vector2d dx(1, 1);

    for(int i = 0; i < P.rows(); ++i)
        for(int j = 0; j < P.cols(); ++j)
            if(i == j)
                P(i, j) = 1.0 / weight[i];
            else
                P(i, j) = 0;
    P.normalize();
    while (dx.norm() > 1e-3)
    {
        for(int i = 0; i < obs.size(); ++i) {
            double dist1 = dist(ref[i], station);
            B(i, 0) = (station(0, 0) - ref[i](0, 0)) / dist1;
            B(i, 1) = (station(1, 0) - ref[i](1, 0)) / dist1;

            // P(i, i) = 1.0 / weight[i];

            l(i, 0) = obs[i] - dist1;
        }
        Matrix2d left = (B.transpose() * P * B);
        dx = left.inverse() * B.transpose() * P * l;
        station += dx;
        // cout << dx << endl << endl;; 
        // break;
    }
    // MatrixXd sigma = (B.transpose() * P * B).inverse() / 2.0;
    MatrixXd v = B * dx - l;
    cout << v.transpose() << endl;
    cout << P << endl << endl;
    MatrixXd sigma = v.transpose() * P * v / 2.0;

    ofstream out("./result/result_uwb.txt", ios::app);
    out << station.transpose() << endl;

    ofstream out_sigma("./result/result_sigma.txt", ios::app);
    out_sigma << sigma << endl;


    // cout << station << endl << endl;
}