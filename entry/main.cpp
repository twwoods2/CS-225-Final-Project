#include "Airport.h"
#include "Edge.h"
#include "Utilities.h"
#include "FlightGraph.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<Airport> airport_nodes;
    ifstream ifs{"../data/airports.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line; // ex: 1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"

         // we need row[1] (airport_name) && row[4] (airport id) && row[6] (latitude) && row[7] (longitude) 
         // airport_name && airport id && latitude && longitude
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }
    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        Edge to_add(sections.at(2), sections.at(4), stod(sections.at(3)), stod(sections.at(4)));
        //checking the route exists in data
        bool start = false;
        bool end = false;
        for (size_t i = 0; i < airport_nodes.size(); i++) {
            if (airport_nodes.at(i).get_id() == sections.at(0)) {
                start = true;
            } else if (airport_nodes.at(i).get_id() == sections.at(1)) {
                end = true;
            }
        }
        //intializing weights
         if (start && end) {
            routes.push_back(to_add);
         }
        }
    cout << "building graph please wait ..." << endl;
    FlightGraph graph = FlightGraph(airport_nodes, routes);
    int input1 = 0;
    int input2 = 0;
    pair<vector<int>,double> test_djk = graph.Dijkstra(input1, input2);
     vector<int> path = test_djk.first;
     double distance = test_djk.second;

    cout << "Route from " << GetNodeInt(input1).get_id() << " -> " <<  GetNodeInt(input2).get_id << endl;

    for (size_t i = 0; i < path.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << path.at(i) << " -> ";

        if (i == path.size() - 1) {
            cout << " Destination Reached!" << endl;
            cout << "Flight Distance: " << distance << " km" <<  endl;
        }
    }
}
