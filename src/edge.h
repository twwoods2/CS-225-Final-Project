#pragma once
#include <string>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

class Edge {
    public:
    Edge();
    Edge(string start, string end);
    string getStart();
    string getEnd();
    void set_dist(double dist);

    private:
    string start_;
    string end_;
    pair<string,string> route_;
    double route_dist_;
};