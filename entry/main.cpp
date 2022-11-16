#include "Airport.h"
#include "Utilities.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<Airport> airport_node;
    ifstream ifs{"../CS-225-Final-Project/entry/airports.csv"};
    if (ifs.is_open()) cout << "dub" << endl;
    for (string line; getline(ifs, line); line = "") {
        
        string row = line; // ex: 1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"

         // we need row[1] (airport_name) && row[4] (airport id) && row[6] (latitude) && row[7] (longitude) 
         // airport_name && airport id && latitude && longitude

        std::cout << line << std::endl;
        vector<string> sections = GetSubstrs(line, ',');
        }
    
    std::cout << "end" << std::endl;
    return 0;
}
