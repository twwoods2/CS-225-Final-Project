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

    void graphicalOutput(const std::vector<Vertex> &path);

//Function to convert latitude/longitude values to correct pixel location on worldMap.
    int convertToPixel(double val, bool lat);

    void plotLineLow(int x0, int y0, int x1, int x2, PNG &png);
 
    void plotLineHigh(int x0, int y0, int x1, int x2, PNG &png);



    private:
    PNG worldMap;
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