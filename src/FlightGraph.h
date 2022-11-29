#pragma once 

#include "Airport.h"
#include "Edge.h"
#include "../lib/cs225/PNG.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


class FlightGraph {
    
    public:

    FlightGraph() {
        airports_ = vector<Airport>();
        routes_ = vector<Edge>();
    }

    FlightGraph(vector<Airport> airport_nodes, vector<Edge> edge_nodes);



    vector<Airport> GetNeighbors(Airport airport); // gets airport by nodes
    vector<Edge> GetNeighbors(string id); // overloaded function that finds the airport node and finds its neighbors

    void Shortestpath(); //to do

    vector<Airport> GetAirports() {return airports_;}
    vector<Edge> GetEdges() {return routes_;}



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