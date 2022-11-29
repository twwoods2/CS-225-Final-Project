#include "Airport.h"
#include "Edge.h"
#include "Utilities.h"
#include "FlightGraph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

int main() {
    vector<Airport> airport_nodes;
    ifstream ifs{"/workspaces/CS 225/CS-225-Final-Project/entry/airports.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line; // ex: 1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"

         // we need row[1] (airport_name) && row[4] (airport id) && row[6] (latitude) && row[7] (longitude) 
         // airport_name && airport id && latitude && longitude
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4)); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"/workspaces/CS 225/CS-225-Final-Project/data/routes_cleaned.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        Edge to_add(sections.at(0), sections.at(1));
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
         if (start && end) {
            routes.push_back(to_add);
         }
        }
    cout << "building graph please wait ..." << endl;
    FlightGraph graph = FlightGraph(airport_nodes, routes);
    cout << "Graph done" << endl;
    // test // 
    int amount_passed = 0;
    //checking if airports and routes were added correctly

    if (airport_nodes.size() == graph.GetAirports().size()) {
        cout << "airport nodes were added correctly" << endl;
        amount_passed++;
    } else {
        cout << "error in adding airport nodes" << endl;
    }

    if (routes.size() == graph.GetEdges().size()) {
        cout << "routes were added correctly" << endl;
        amount_passed++;
    } else {
        cout << "error in adding routes" << endl;
    }
    //////////////////////////////////////////////////////////////////////

    // test to check the correct amount of neighbors of nodes

    vector<Airport> test = graph.GetNeighbors(airport_nodes.at(3630)); //checking neighbors of O'hare international airport (expected amount of neighbors: 558)

    if (test.size() == 558) {
        cout << "correct amount of neighbors of node" << endl;
        amount_passed++;
    } else {
        cout << "incorrect amount of neighbors" << endl;
    }

    //test to check the correct neighbor in test vector (expected: BRL)

    if (test.at(0).get_id() == "BRL") {
        cout << "correct first neighbor" << endl;
        amount_passed++;
    } else {
        cout << "incorrect first neighbor" << endl;
    }
    
    cout << "tests complete! Passed tests : " << amount_passed << endl;
    return 0;
    
}