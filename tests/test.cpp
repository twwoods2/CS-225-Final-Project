#include <catch2/catch_test_macros.hpp>

#include "Airport.h"
#include "Edge.h"
#include "Utilities.h"
#include "FlightGraph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

//your code here

TEST_CASE("Free Points", "[weight=5]"){
    REQUIRE( 1 == 1);
}

TEST_CASE("bfs Algorithm (1)", "[weight=5]"){
    vector<Airport> airport_nodes;
    ifstream ifs{"/workspaces/cs225env/CS-225-Final-Project/data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"/workspaces/cs225env/CS-225-Final-Project/data/routes_cleaned.csv"};
    
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
         if (start && end) {
            routes.push_back(to_add);
         }
        }

    //cout << "building condensed graph please wait ..." << endl;
    FlightGraph graph = FlightGraph(airport_nodes, routes);
    //cout << "Graph done" << endl;

    //cout << "Starting BFS Algo" << endl;

    vector<int> test_bfs = graph.bfs(3469, 3830);

    //cout << "BFS Algo Done. Starting the print the result... " << endl;

    cout << "Route from SFO -> ORD" << endl;

    for (size_t i = 0; i < test_bfs.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << test_bfs.at(i) << " -> ";

        if (i == test_bfs.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }

    vector<int> answer = {3469, 3830};
    REQUIRE (test_bfs == answer);
}

TEST_CASE("bfs Algorithm (2)", "[weight=5]"){
    vector<Airport> airport_nodes;
    ifstream ifs{"/workspaces/cs225env/CS-225-Final-Project/data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"/workspaces/cs225env/CS-225-Final-Project/data/routes_cleaned.csv"};
    
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
         if (start && end) {
            routes.push_back(to_add);
         }
        }

    FlightGraph graph = FlightGraph(airport_nodes, routes);

    cout << "Route from ORD -> CMI" << endl;

    vector<int> test_bfs = graph.bfs(3830, 4049);

    for (size_t i = 0; i < test_bfs.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << test_bfs.at(i) << " -> ";

        if (i == test_bfs.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }
    vector<int> answer = {3830, 4049};
    REQUIRE (test_bfs == answer);
}

TEST_CASE("bfs Algorithm (3)", "[weight=5]"){
    vector<Airport> airport_nodes;
    ifstream ifs{"/workspaces/cs225env/CS-225-Final-Project/data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"/workspaces/cs225env/CS-225-Final-Project/data/routes_cleaned.csv"};
    
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
         if (start && end) {
            routes.push_back(to_add);
         }
        }

    FlightGraph graph = FlightGraph(airport_nodes, routes);

    cout << "Route from SFO -> CMI" << endl;

    vector<int> test_bfs = graph.bfs(3469, 4049);

    for (size_t i = 0; i < test_bfs.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << test_bfs.at(i) << " -> ";

        if (i == test_bfs.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }
    vector<int> answer = {3469,3830,4049};
    REQUIRE (test_bfs == answer);
}

TEST_CASE("bfs Algorithm (World Cup(1))", "[weight=5]"){
    vector<Airport> airport_nodes;
    ifstream ifs{"/workspaces/cs225env/CS-225-Final-Project/data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"/workspaces/cs225env/CS-225-Final-Project/data/routes_cleaned.csv"};
    
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
         if (start && end) {
            routes.push_back(to_add);
         }
        }

    FlightGraph graph = FlightGraph(airport_nodes, routes);


    vector<int> sfo_doha = graph.bfs(3469, 11051);
    
    cout << "Route from SFO -> Doha" << endl;

    for (size_t i = 0; i < sfo_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << sfo_doha.at(i) << " -> ";

        if (i == sfo_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }

    vector<int> lax_doha = graph.bfs(3484, 11051);

    cout << "Route from LAX -> Doha" << endl;

    for (size_t i = 0; i < lax_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << lax_doha.at(i) << " -> ";

        if (i == lax_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }
    vector<int> itm_doha = graph.bfs(2334, 11051);
    cout << "Route from Osaka -> Doha" << endl;

    for (size_t i = 0; i < itm_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << itm_doha.at(i) << " -> ";

        if (i == itm_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }
    vector<int> lis_doha = graph.bfs(1638, 11051);

    cout << "Route from Portugal -> Doha" << endl;

    for (size_t i = 0; i < lis_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << lis_doha.at(i) << " -> ";

        if (i == lis_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }




    //vector<int> answer = {3469,3830,4049};
    //REQUIRE (test_bfs == answer);
}

TEST_CASE("bfs Algorithm (World Cup(2))", "[weight=5]"){
    vector<Airport> airport_nodes;
    ifstream ifs{"/workspaces/cs225env/CS-225-Final-Project/entry/airports.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"/workspaces/cs225env/CS-225-Final-Project/data/routes_cleaned.csv"};
    
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
         if (start && end) {
            routes.push_back(to_add);
         }
        }

    FlightGraph graph = FlightGraph(airport_nodes, routes);


    vector<int> sfo_doha = graph.bfs(3469, 11051);
    
    cout << "Route from SFO -> Doha" << endl;

    for (size_t i = 0; i < sfo_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << sfo_doha.at(i) << " -> ";

        if (i == sfo_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }

    vector<int> lax_doha = graph.bfs(3484, 11051);

    cout << "Route from LAX -> Doha" << endl;

    for (size_t i = 0; i < lax_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << lax_doha.at(i) << " -> ";

        if (i == lax_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }
    vector<int> itm_doha = graph.bfs(2334, 11051);
    cout << "Route from Osaka -> Doha" << endl;

    for (size_t i = 0; i < itm_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << itm_doha.at(i) << " -> ";

        if (i == itm_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }
    vector<int> lis_doha = graph.bfs(1638, 11051);

    cout << "Route from Portugal -> Doha" << endl;

    for (size_t i = 0; i < lis_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << lis_doha.at(i) << " -> ";

        if (i == lis_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }

    vector<int> answer1 = {3469,3077,11051};
    vector<int> answer2 = {3484,2564,11051};
    vector<int> answer3 = {2334,2279,11051};
    vector<int> answer4 = {1638,507,11051};
    REQUIRE (sfo_doha == answer1);
    REQUIRE (lax_doha == answer2);
    REQUIRE (itm_doha == answer3);
    REQUIRE (lis_doha == answer4);
}