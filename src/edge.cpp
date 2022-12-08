#include <edge.h>
using namespace std;

Edge::Edge() {
    start_ = "";
    end_ = "";
    route_ = pair<string,string>(start_, end_);
}
Edge::Edge(string start, string end, int source_id, int dest_id) {
    start_ = start;
    end_ = end;
    route_ = pair<string,string>(start,end);
    start_id = source_id;
    end_id = dest_id;
}

string Edge::getStart() {
    return start_;
}
string Edge::getEnd() {
    return end_;
}

void Edge::set_dist(double dist) {
    route_dist_ = dist;
}