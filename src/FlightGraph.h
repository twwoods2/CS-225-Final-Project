#pragma once 
#include "Airport.h"
#include "Edge.h"
#include "../lib/cs225/PNG.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>
#include <queue>
#include <algorithm>
#include <functional>
#include <limits>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <iterator>
using namespace std;


class FlightGraph {
    
    public:

    FlightGraph() {
        airports_ = vector<Airport>();
        routes_ = vector<Edge>();
    }

    FlightGraph(vector<Airport> airport_nodes, vector<Edge> edge_nodes);



    vector<Airport> GetNeighbors(Airport airport); // gets airport by nodes
    Airport GetNode(string id);
    vector<Edge> GetNeighborsEdge(string id); // overloaded function that finds the airport node and finds its neighbors
    
    vector<Airport> Dijkstra(Airport start, Airport end);

    vector<Airport> GetAirports() {return airports_;}
    vector<Edge> GetEdges() {return routes_;}

    vector<Airport> solve(Airport start);
    vector<Airport> constrcutpath(Airport start, Airport end, vector<Airport> path);
    vector<Airport> bfs(Airport start, Airport end);



    private:

    vector<Airport> airports_;
    vector<Edge> routes_;
    double distance_hlpr(double startX, double startY, double endX, double endY) {
        double square = (endX - startX)*(endX - startX) - (endY - startY)*(endY-startY);
        if (square < 0) {
            return - sqrt(std::abs(square));
        } else {
            return sqrt(std::abs(square));
        }
    }
    
};