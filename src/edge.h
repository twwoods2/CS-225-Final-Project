#pragma once
#include <string>
#include <vector>
#include <utility>
using namespace std;

class edge {
    public:
    edge();
    edge(string start, string end);
    string getStart();
    string getEnd();
    void set_dist(double dist);

    private:
    string start_;
    string end_;
    pair<string,string> route_;
    double route_dist_;
};