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
    ifstream ifs{"/workspaces/CS 225/CS-225-Final-Project/entry/airports.csv"};
    if (ifs.is_open()) cout << "dub" << endl;
    int c = 0;
    for (string line; getline(ifs, line); line = "") {
        
        string row = line; // ex: 1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"

         // we need row[1] (airport_name) && row[4] (airport id) && row[6] (latitude) && row[7] (longitude) 
         // airport_name && airport id && latitude && longitude
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4)); //stod converts string to double
        airport_nodes.push_back(to_add);
        c++;
    }

    std::cout << "nodes : " << c << endl;
    vector<Edge> routes;
    ifstream ifs_two{"/workspaces/CS 225/CS-225-Final-Project/data/routes_cleaned.csv"};
    if (ifs_two.is_open()) cout << "dub" << endl;
    
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
        //intializing weights
         if (start && end) {
            routes.push_back(to_add);
         }
        }
    cout << "building graph please wait ..." << endl;
    FlightGraph graph = FlightGraph(airport_nodes, routes);
    //test 
    vector<Airport> test = graph.GetNeighbors(airport_nodes.at(3630));
    std::cout << test.size() << " " << test.at(0).get_id() << std::endl;
    std::cout << "end" << std::endl;
    return 0;
}
