#include "Airport.h"
#include "Edge.h"
#include "Utilities.h"

#include "FlightGraph.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    cout << "\n" << endl;
    cout << "Welcome! Please wait for the constructing of our graph." << endl;
    cout << "\n" << endl;
    vector<Airport> airport_nodes;
    ifstream ifs{"../data/airports.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0)));
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    cout << "Loading.." << endl;
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            bool start = false;
            bool end = false;
            for (size_t i = 0; i < airport_nodes.size(); i++) {
                if (airport_nodes.at(i).get_id() == sections.at(2)) {
                start = true;
                } else if (airport_nodes.at(i).get_id() == sections.at(4)) {
                end = true;
            }
            }
            if (start && end) {
                routes.push_back(to_add);
            }
         }
        }
    cout << "building graph please wait ..." << endl;
    cout << "\n" << endl;

    FlightGraph graph = FlightGraph(airport_nodes, routes);

    //user inputs starting airport and end airport
    cout << "Where would like to go? Please input the starting and ending airport by their abbrievated terms ex('LAX','ORD', 'DOH')" << endl;
    cout << "\n" << endl;

    string start, end;
    cout << "inserting "; cin >> start >> end;
    cout << "\n" << endl;
    cout << "Finding airports, please wait..." << endl; 
    cout << "\n" << endl;

    int input1 = graph.GetNode(start).get_sourceid();
    int input2 = graph.GetNode(end).get_sourceid();


    if (input1 == -1 || input2 == -1) {
        cout << "Invalid airports" << endl;
        return 0;
    }


    cout << "Airports found!" << endl;
    cout << "\n" << endl;
    cout << "Generating shortest path. Please wait.." << endl;


    pair<vector<int>,double> test_djk = graph.Dijkstra(input1, input2);
     vector<int> path = test_djk.first;
     double distance = test_djk.second;


    cout << "Route from " << graph.GetNodeInt(input1).get_id() << " -> " <<  graph.GetNodeInt(input2).get_id() << endl;

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
    cs225::PNG world_map;
    world_map.readFromFile("../tests/map.png");

    graph.pathVisualizer(world_map, graph.GetVectorAirport(path), "../entry/useroutput.png");
}
