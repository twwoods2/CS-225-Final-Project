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
vector<Edge> FlightGraph::GetNeighborsEdge(string id) { 
    vector<Edge> search;
    for (size_t i = 0; i < routes_.size(); i++) {
        if (id == routes_.at(i).getStart()) {
            search.push_back(routes_.at(i));
        }
    }
    return search;
}
vector<Airport> FlightGraph::Dijkstra(Airport start, Airport end) {
    priority_queue<pair<double, Airport>> p_queue;
    set<Airport> visited;
    pair<double, Airport> begin = pair<double, Airport>(0, start);
    p_queue.push(begin);
    map<Airport,double> dist;

    map<string, string> neighborIDToCurrent;
    for (size_t i = 0; i < airports_.size(); i++) {
        dist[airports_.at(i)] = numeric_limits<double>::infinity();
        vector<Airport> neighbors = GetNeighbors(airports_.at(i));
        for (size_t j = 0; j < neighbors.size(); j++) {
            neighborIDToCurrent[neighbors.at(j).get_id()] = airports_.at(i).get_id();
        }
    }
    dist[start] = 0;
    while (!p_queue.empty() && p_queue.top().second.get_id() != end.get_id()) {
        Airport current = p_queue.top().second;
        double w = p_queue.top().first;

        vector<Edge> neighbor_edge = GetNeighborsEdge(current.get_id());
        for (size_t i = 0; i < neighbor_edge.size(); i++) {
            Edge edge = neighbor_edge.at(i);
            Airport neighbor_node = GetNode(edge.getEnd());
            if (neighbor_node.get_id() == "") continue;

            if (visited.find(neighbor_node) == visited.end()) {
                if (abs(w) + edge.get_dist() < dist[neighbor_node]) {
                    dist[neighbor_node] = abs(w) + edge.get_dist();
                }
                p_queue.push(make_pair(-1.0 * dist[neighbor_node], neighbor_node));
                neighborIDToCurrent[neighbor_node.get_id()] = current.get_id();
            }
        }
        visited.insert(current);
        p_queue.pop();

    }
    vector<Airport> shortest;
    Airport destination = end;
    
    while (neighborIDToCurrent[destination.get_id()] != start.get_id()) {
        shortest.push_back(destination);
        destination = GetNode(neighborIDToCurrent[destination.get_id()]);
    }
    shortest.push_back(start);
    

    
    return shortest;
}
Airport FlightGraph::GetNode(string id) {
    Airport to_return;
    for (Airport temp : airports_) {
        if (temp.get_id() == id) {
            to_return = temp;
            break;
        }
    }
    return to_return;
}