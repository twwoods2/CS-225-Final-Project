#include "Airport.h"
#include "Edge.h"
#include "Utilities.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<Airport> airport_nodes;
    ifstream ifs{"/workspaces/CS 225/CS-225-Final-Project/entry/airports.csv"};
    if (ifs.is_open()) cout << "dub" << endl;
    for (string line; getline(ifs, line); line = "") {
        
        string row = line; // ex: 1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"

         // we need row[1] (airport_name) && row[4] (airport id) && row[6] (latitude) && row[7] (longitude) 
         // airport_name && airport id && latitude && longitude

        //std::cout << line << std::endl;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4)); //stod converts string to double
        cout << to_add.get_lat_long().first << " " << to_add.get_lat_long().second << endl;
        airport_nodes.push_back(to_add);
    }
    vector<Edge> routes;
    ifstream ifs_two{"/workspaces/CS 225/CS-225-Final-Project/data/routes_cleaned.csv"};
    if (ifs_two.is_open()) cout << "dub" << endl;
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        Edge to_add(sections.at(0), sections.at(1));
        cout << "dest " << sections.at(0) << " " << sections.at(1) << endl;
        routes.push_back(to_add);
    }
    
    std::cout << "end" << std::endl;
    return 0;
}
