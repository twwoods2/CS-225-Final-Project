#pragma once
#include <string>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

class Edge {
    public:
    Edge();
    Edge(string start, string end, int source_id, int dest_id);
    int getStartId() {return start_id;}
    int getEndId() {return end_id;}
    string getStart();
    string getEnd();
    double get_dist() {return route_dist_;}
    void set_dist(double dist);

    private:
    int start_id;
    int end_id;
    string start_;
    string end_;
    pair<string,string> route_;
    double route_dist_;
};