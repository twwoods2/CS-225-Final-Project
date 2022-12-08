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
    //making neighbors using unordered_map<int, vector<Airports> neighbors
    unordered_map<int, vector<Airport>> neighbors;
    for (size_t i = 0; i < airports_.size(); i++) {

        int airport_id = airports_.at(i).get_sourceid();
        vector<Airport> temp_n;
        for (size_t j = 0; j < routes_.size(); j++) {

            if (airports_.at(i).get_id() == routes_.at(j).getStart()) {

                string to_find = routes_.at(j).getEnd();
                for (Airport search : airports_) {
                    
                    if (search.get_id() == to_find) {
                        
                        temp_n.push_back(search);

                    }

                }

            }
            

        }
        if (!temp_n.empty()) {

            neighbors.insert(make_pair(airport_id, temp_n));

        }
    }
    neighbors_ = neighbors;
    cout << "done building graph ..." << endl;
}

vector<Airport> FlightGraph::GetNeighbors(Airport airport) {
    vector<Airport> search;
    for (size_t i = 0; i < routes_.size(); i++) {

        if (airport.get_id() == routes_.at(i).getStart()) {
            string neighbor_id = routes_.at(i).getEnd();
            for (size_t j = 0; j < airports_.size(); j++) {
                
                if (neighbor_id == airports_.at(j).get_id()) {
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
vector<int> FlightGraph::Dijkstra(int start, int end) {
    // init distance vector
    vector<double> dist;
    dist.resize(14110, INT_MAX);
    dist.at(start) = 0;

    // init previous vector
    vector<int> prev;
    prev.resize(14110, 0);

    // init priority queue
    priority_queue<pair<int,double>> pq; // pair<airport(index) , distance>
    pq.push(make_pair(start,0.0));

    // initialize visited check vector
    vector<bool> visited;
    visited.resize(14110, false);
    visited[start] = true;

    while (!pq.empty()) {
        pair<int,double> tmp = pq.top();
        pq.pop();
        int idx = tmp.first;
        double cur_dist = tmp.second;

        // mark the new node as visisted
        visited[idx] = true;

        //obtain edges from current index and to get distances
        Airport curr_airport = GetNodeInt(idx);
        string curr_string = curr_airport.get_id();
        vector<Edge> edge_dist = GetNeighborsEdge(curr_string);

        // overcoming stale pushes

        if (dist[idx] < cur_dist) { continue; }


        // loop over neighbors of current node and skip visited nodes
        for (size_t i = 0; i < GetNeighbors(curr_airport).size(); i++) {
            int tmp_airport = GetNeighbors(curr_airport).at(i).get_sourceid();
            double edge_cost;
            // obtain dist to node from current idx
            // loop through all the edges in the neighboring edges 
            for (size_t j = 0; j < edge_dist.size(); j++) {
                // check that the start and end of the current edge match the integers
                if (edge_dist.at(j).getStartId() == idx && edge_dist.at(j).getEndId() == tmp_airport) {
                    // if the start and end work, pull the distance value
                    // this distance represents the distance from current index to tmp_airport
                    edge_cost = edge_dist.at(j).get_dist();
                }
            }
            if (visited[GetNeighbors(idx).at(i).get_sourceid()] == true) {
                continue;
            } else {
                double newDist = dist[idx] + edge_cost;
                // checking if the newDist is smaller than current dist
                dist[tmp_airport] = min(newDist, dist[tmp_airport]);
                pq.push(make_pair(tmp_airport,newDist));
                prev[tmp_airport] = idx;
            }
        }
    }

    // building the path
    vector<int> path;
    if (dist[end] == INT_MAX) {
        cout << "There is no path to the airports!" << endl;
        return path;
    }
    for (int k = end; k != 0; k = prev[k]) {
        path.push_back(k);
    }

    std::reverse(path.begin(), path.end());

    return path;

}
/*

initialize distances  // initialize tentative distance value
  initialize previous   // initialize a map that maps current node -> its previous node
  initialize priority_queue   // initialize the priority queue
  initialize visited

  while the top of priority_queue is not destination:
      get the current_node from priority_queue
      for neighbor in current_node's neighbors and not in visited:
          if update its neighbor's distances:
              previous[neighbor] = current_node
      save current_node into visited

  extract path from previous
  return path and distance
  */



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
Airport FlightGraph::GetNodeInt(int id) {
    Airport to_return;
    for (Airport temp : airports_) {
        if (temp.get_sourceid() == id) {
            to_return = temp;
            break;
        }
    }
    return to_return;
}

// BREADTH FIRST SEARCH //

vector<int> FlightGraph::solve(int start) {

    //Airport dummy = Airport(0,0,"dummy","dum",-1);

    // create a list of bools to make airports as visited
    vector<bool> visited;
    //vector<bool> visited;
    visited.resize(14110, false);
    visited[start] = true;

    // queue for upcoming airports
    queue<int> q;
    q.push(start);

    // what were returning
    // map of airpots <current airport, previous airport>
    vector<int> path;
    path.resize(14110, 0);

    while(!q.empty())
    {
        // Dequeue a vertex from queue and print it
        int tmp = q.front();
        // cout << s << " ";
        q.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        //vector<Airport> neighbors = GetNeighbors(tmp);
        Airport beg = GetNodeInt(tmp);
        for (auto adjacent: GetNeighbors(beg))
        {
            int ref = adjacent.get_sourceid();
            if (!visited[ref])
            {
                visited[ref] = true;
                q.push(ref);
                path[ref] = tmp;
            }
        }
    }

    return path;
}
vector<int> FlightGraph::constrcutpath(int start, int end, vector<int> path) {
    vector<int> toreturn;
    vector<int> empty;

    //Airport dummy = Airport(0,0,"dummy","dum",-1);

    for (int tmp = end; tmp != 0; tmp = path[tmp]) {
        toreturn.push_back(tmp);
    }

    std::reverse(toreturn.begin(), toreturn.end());

    if (toreturn[0] == start) {
        return toreturn;
    } else {
        cout << "No path between both points!" << endl;
        return empty;
    }


}

vector<int> FlightGraph::bfs(int start, int end) {

    vector<int> path = solve(start);

    return constrcutpath(start, end, path);

}