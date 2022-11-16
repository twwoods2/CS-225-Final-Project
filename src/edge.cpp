#include <edge.h>
using namespace std;

edge::edge() {
    start_ = "";
    end_ = "";
    route_ = pair<string,string>(start_, end_);
}
edge::edge(string start, string end) {
    start_ = start;
    end_ = end;
    route_ = pair<string,string>(start,end);
}

string edge::getStart() {
    return start_;
}
string edge::getEnd() {
    return end_;
}

void edge::set_dist(double dist) {
    route_dist_ = dist;
}