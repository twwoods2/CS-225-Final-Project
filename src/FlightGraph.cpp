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

// ADJACENCY LIST // 

vector<Airport> FlightGraph::GetNeighbors(Airport airport) {
    return neighbors_[airport.get_sourceid()];
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

// DJIKSTRA //

pair<vector<int>,double> FlightGraph::Dijkstra(int start, int end) {
    // check that its a valid airport?

    // init distance vector
    vector<double> dist;
    dist.resize(14110, INT_MAX);
    dist.at(start) = 0;

    // init previous vector
    vector<int> prev;
    prev.resize(14110, 0);

    // init priority queue
    priority_queue<pair<int, double>, vector<pair<int, double>>, Compare> pq; // pair<airport(index) , distance>
    pq.push(make_pair(start,0.0));

    // initialize visited check vector
    vector<bool> visited;
    visited.resize(14110, false);
    visited[start] = true;

    bool flag = false;
    while (!pq.empty() && !flag) {
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
                    // this distance represents the distance from current index to tmp_airport or the route
                    edge_cost = edge_dist.at(j).get_dist();
                }
            }
            // skipping over aiports we have already visited
            if (visited[GetNeighbors(curr_airport).at(i).get_sourceid()] == true) {
                continue;
            } else {
                double newDist = dist[idx] + edge_cost;
                // checking if the newDist is smaller than current dist
                if (newDist < dist[tmp_airport]) {
                    dist[tmp_airport] = newDist;
                    pq.push(make_pair(tmp_airport,newDist));
                    prev[tmp_airport] = idx;
                }
            }
            // checking if we have reached the end node yet
            if (tmp_airport == end) {
                flag = true;
                break;
            }
        }
    }

    // building the path
    vector<int> path;
    double total_dist = 0;
    // checking that the path exists (if it doesnt than destination will be infinite)
    if (dist[end] == INT_MAX) {
        cout << "There is no path to the airports!" << endl;
        return make_pair(path,total_dist);
    }
    // calculating the total distance;
    for (int k = end; k != 0; k = prev[k]) {
        path.push_back(k);
        total_dist += dist[k];
    }

    std::reverse(path.begin(), path.end());

    return make_pair(path, total_dist);

}

// NODE CONVERSIONS //

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
vector<int> FlightGraph::constructpath(int start, int end, vector<int> path) {
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

    return constructpath(start, end, path);

}

vector<Airport> FlightGraph::GetVectorAirport(vector<int> shortPath) {
    vector<Airport> toreturn;
    if (shortPath.empty()) { return toreturn; }

    for (size_t i = 0; i < shortPath.size(); i++) {
        Airport tmp = GetNodeInt(shortPath.at(i));
        toreturn.push_back(tmp);
    }  

    return toreturn;
}

void FlightGraph::pathVisualizer(cs225::PNG worldMap, vector<Airport> path, string filename) {
    worldMap.resize(worldMap.width(), worldMap.height());
    vector<pair<double, double>> airport_x_y;
    for(unsigned i = 0; i < path.size(); i++){
                // double x = (airports.at(i).second+180)(worldMap.width()/360)
            double lat = path[i].get_lat_long().first;
            double latRad = toRadians(lat);
            if (tan((3.14 / 4) + (latRad / 2)) < 0)
            {
                continue;
            }
            double mercVal = log(tan((3.14/4)+(latRad/2))) * (worldMap.width()/(2*3.14));
            double longRad = toRadians(path[i].get_lat_long().second + 180);
            double x = longRad * (worldMap.width()/(2*3.14));
            double y = worldMap.height()/2 - mercVal;

            for (int xd = -2; xd < 3; xd++) {
                for (int yd = -2; yd < 3; yd++) {
                    cs225::HSLAPixel& pix = worldMap.getPixel(xd + x , yd + y);
                    pix = cs225::HSLAPixel(0,1.0,0.5,1);
                }
            }
            airport_x_y.push_back(pair<double, double>(x, y));

    }
    for (size_t  i = 0; i < airport_x_y.size() - 1; i++) {
        double start_x = airport_x_y.at(i).first;
        double start_y = airport_x_y.at(i).second;
        double end_x = airport_x_y.at(i + 1).first;
        double end_y = airport_x_y.at(i + 1).second;

        if(start_x > end_x) iter_swap(airport_x_y.begin() + i, airport_x_y.begin() + (i+1));
    }
    for (size_t  i = 0; i < airport_x_y.size() - 1; i++) {

        double start_x = airport_x_y.at(i).first;
        double start_y = airport_x_y.at(i).second;
        double end_x = airport_x_y.at(i + 1).first;
        double end_y = airport_x_y.at(i + 1).second;

        double a = ((double)end_y - (double)start_y) / ((double)end_x - (double)start_x);
        double b = (double)start_y - (a * (double)start_x);

        double curr_x = start_x;
        double curr_y = start_y;

        while (curr_x <= end_x) {
                worldMap.getPixel(curr_x, curr_y) = cs225::HSLAPixel(180, 1, 0.5, 1);

                if (a <= 0) { // moving upright
                    if (curr_y < end_y) {break;}
                    double rightSlope = getSlope(curr_x + 1, curr_y, b);
                    double upSlope = getSlope(curr_x, curr_y - 1, b);
                    if (abs(abs(rightSlope) - abs(a)) < abs(abs(upSlope) - abs(a))) {
                        curr_x++;
                        continue;
                    } //moving right
                    else if (abs(abs(rightSlope) - abs(a)) > abs(abs(upSlope) - abs(a))) {
                        curr_y--;
                        continue;
                    } //moving up
                    else {
                        curr_x++;
                        curr_y--;
                        continue;
                    }
                } 
                else { // moving downright
                    if (curr_y > end_y) {break;}
                    double rightSlope = getSlope(curr_x + 1, curr_y, b);
                    double downSlope = getSlope(curr_x, curr_y + 1, b);
                    if (abs(abs(rightSlope) - abs(a)) < abs(abs(downSlope) - abs(a))) {
                        curr_x++;
                        continue;
                    } //moving right
                    else if (abs(abs(rightSlope) - abs(a)) > abs(abs(downSlope) - abs(a))) {
                        curr_y++;
                        continue;
                    } //moving down
                    else {
                        curr_x++;
                        curr_y++;
                        continue;
                    }
                } 
            }
        }

    cs225::PNG output = worldMap;
    output.writeToFile(filename); 
}

double FlightGraph::getSlope(double x, double y, double y_int) {
    return ((y - y_int) / x);
}
