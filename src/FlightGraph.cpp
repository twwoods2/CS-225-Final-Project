#include "FlightGraph.h"
using namespace std;

//constructor 
//set the vectors
//set weights

FlightGraph::FlightGraph(vector<Airport> airport_nodes, vector<Edge> edge_nodes) {
    airports_ = airport_nodes;
    routes_ = edge_nodes;
    
    
    //set weights
    for (size_t i = 0; i < edge_nodes.size(); i++) {
        string first_id = routes_.at(i).getStart();
        string second_id = routes_.at(i).getEnd();
        Airport begin; 
        Airport end;

        for (size_t j = 0; j < airports_.size(); j++) {
            
            if (first_id == airports_.at(j).get_id()) {
                begin = airports_.at(j);
            } else if (second_id == airports_.at(j).get_id()) {
                end = airports_.at(j);
            }
        }
        if (begin.get_id() == "" || end.get_id() == "") {
            continue;
        }
        double weight = distance_hlpr(begin.get_lat_long().second, begin.get_lat_long().first, end.get_lat_long().second, end.get_lat_long().first);
        routes_.at(i).set_dist(weight);
    }
    cout << "done building graph ..." << endl;
}

vector<Airport> FlightGraph::GetNeighbors(Airport airport) {
    vector<Airport> search;
    for (size_t i = 0; i < routes_.size(); i++) {

        if (airport.get_id() == routes_.at(i).getStart()) {
            string neighbor_id = routes_.at(i).getEnd();
            for (size_t j = 0; j < airports_.size(); j++) {
                
                if (neighbor_id == airports_.at(j).get_id()) {
                    cout << "dub in the function" << endl;
                    search.push_back(airports_.at(j));
                }
            }
        }
    }
    return search;
}