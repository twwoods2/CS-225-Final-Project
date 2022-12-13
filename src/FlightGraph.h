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
#include <unordered_map>
#include <bits/stdc++.h>
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
    Airport GetNodeInt(int id);
    vector<Edge> GetNeighborsEdge(string id); // overloaded function that finds the airport node and finds its neighbors
    
    pair<vector<int>,double> Dijkstra(int start, int end);
    //pair<vector<int>, double> shortestPath(vector<int> path, double distance);
    

    vector<Airport> GetAirports() {return airports_;}
    vector<Edge> GetEdges() {return routes_;}

    vector<int> solve(int start);
    vector<int> constructpath(int start, int end, vector<int> path);
    vector<int> bfs(int start, int end);

    vector<Airport> GetVectorAirport(vector<int> shortPath);

    void pathVisualizer(cs225::PNG worldMap, vector<Airport> path, string filename);
    double getSlope(double x, double y, double y_int);

    private:
    vector<Airport> airports_;
    vector<Edge> routes_;
    unordered_map<int, vector<Airport>> neighbors_;
    double toRadians(const double deg) {
        double one_deg = (M_PI) / 180;
        return (one_deg * deg);
    }
    double distance_hlpr(double startX, double startY, double endX, double endY) {
        startY = toRadians(startY);
        startX = toRadians(startX);

        endY = toRadians(endY);
        endX = toRadians(endX);

        double dlong = endX - startX;
        double dlat = endY - startY;

        double answer = pow(sin(dlat / 2), 2) + cos(startY) * cos(endY) * pow(sin(dlong/2), 2);
        answer = 2 * asin(sqrt(answer));

        
        double R = 6371;

        answer = answer * R;

        return answer;
        

    }

    class Compare {
        public:
        bool operator()(pair<int, double> p1, pair<int, double> p2) {
            return p1.second > p2.second;
        }
    };
};