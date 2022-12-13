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

TEST_CASE("bfs Algorithm (1)", "[weight=5]"){
    vector<Airport> airport_nodes;
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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
    
    FlightGraph graph = FlightGraph(airport_nodes, routes);



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
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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
    vector<int> answer2 = {3484,3077,11051};
    vector<int> answer3 = {};
    vector<int> answer4 = {1638,478,11051};
    REQUIRE (sfo_doha == answer1);
    REQUIRE (lax_doha == answer2);
    REQUIRE (itm_doha == answer3);
    REQUIRE (lis_doha == answer4);
    
}

TEST_CASE("bfs Algorithm (World Cup(2))", "[weight=5]"){
    vector<Airport> airport_nodes;
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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

    // takes a very long time to run and producing a test case later
}

TEST_CASE("Dijkstra (1)", "[weight=5]") {
    vector<Airport> airport_nodes;
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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
    
    FlightGraph graph = FlightGraph(airport_nodes, routes);

    // BREADTH FIRST SEARCH //

    vector<int> test_bfs = graph.bfs(3077, 4049);

    //cout << "BFS Algo Done. Starting the print the result... " << endl;

    cout << "Route from Hong Kong -> UIUC (BFS)" << endl;

    for (size_t i = 0; i < test_bfs.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << test_bfs.at(i) << " -> ";

        if (i == test_bfs.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }

     pair<vector<int>,double> test_djk = graph.Dijkstra(3077, 4049);
     vector<int> path = test_djk.first;
     double distance = test_djk.second;

    //cout << "BFS Algo Done. Starting the print the result... " << endl;

    cout << "Route from Hong Kong -> UIUC (Djikstra)" << endl;

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

    vector<int> answer = {3077, 3830, 4049};
    REQUIRE( path == answer);
    
}

TEST_CASE("Dijkstra (2)", "[weight=5]") {
    vector<Airport> airport_nodes;
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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
    
    FlightGraph graph = FlightGraph(airport_nodes, routes);

     pair<vector<int>,double> test_djk = graph.Dijkstra(3469, 3830);
     vector<int> path = test_djk.first;
     double distance = test_djk.second;

    //cout << "BFS Algo Done. Starting the print the result... " << endl;

    cout << "Route from SFO -> ORD" << endl;

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

    vector<int> answer = {3469, 3830};
    REQUIRE (path == answer);
}

TEST_CASE("BFS / Dijkstra (1)", "[weight=5]") {
    vector<Airport> airport_nodes;
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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
    
    FlightGraph graph = FlightGraph(airport_nodes, routes);

    // BREADTH FIRST SEARCH //

    vector<int> test_bfs = graph.bfs(4049, 1154);

    //cout << "BFS Algo Done. Starting the print the result... " << endl;

    cout << "Route from UIUC -> Benghazi (BFS)" << endl;

    for (size_t i = 0; i < test_bfs.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << test_bfs.at(i) << " -> ";

        if (i == test_bfs.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }

    // DJIKSTRA // 

     pair<vector<int>,double> test_djk = graph.Dijkstra(4049, 1154);
     vector<int> path = test_djk.first;
     double distance = test_djk.second;

    //cout << "BFS Algo Done. Starting the print the result... " << endl;

    cout << "Route from UIUC-> Benghazi (Dijkstra)" << endl;

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

    vector<int> answer1 = {4049,3830,478,1157,1154};
    vector<int> answer2 = {4049,3830,478,1157,1154};
    
    REQUIRE (path == answer1);
    REQUIRE (test_bfs == answer2);
}

TEST_CASE("BFS / Dijkstra (2)", "[weight=5]") {
    vector<Airport> airport_nodes;
    ifstream ifs{"../data/airports.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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
    
    FlightGraph graph = FlightGraph(airport_nodes, routes);


    // BREADTH FIRST SEARCH //

     vector<int> sfo_doha = graph.bfs(3469, 11051);
    
    cout << "Route from SFO -> Doha (BFS)" << endl;

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

    cout << "Route from LAX -> Doha (BFS)" << endl;

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
    cout << "Route from Osaka -> Doha (BFS)" << endl;

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

    cout << "Route from Portugal -> Doha (BFS)" << endl;

    for (size_t i = 0; i < lis_doha.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << lis_doha.at(i) << " -> ";

        if (i == lis_doha.size() - 1) {
            cout << " Destination Reached!" << endl;
        }
    }

    // DJIKSTRA // 
    cout << "Route from SFO -> ORD (Dijkstra)" << endl;
     pair<vector<int>,double> test_djk1 = graph.Dijkstra(3469, 3830);
     vector<int> path1 = test_djk1.first;
     double distance1 = test_djk1.second;

    for (size_t i = 0; i < path1.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << path1.at(i) << " -> ";

        if (i == path1.size() - 1) {
            cout << " Destination Reached!" << endl;
            cout << "Flight Distance: " << distance1 << " km" <<  endl;
        }
    }
     
     cout << "Route from Lax-> Doha (Dijkstra)" << endl;
     pair<vector<int>,double> test_djk2 = graph.Dijkstra(3484, 11051);
     vector<int> path2 = test_djk2.first;
     double distance2 = test_djk2.second;

    for (size_t i = 0; i < path2.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << path2.at(i) << " -> ";

        if (i == path2.size() - 1) {
            cout << " Destination Reached!" << endl;
            cout << "Flight Distance: " << distance2 << " km" <<  endl;
        }
    }

     cout << "Route from Osaka-> Doha (Dijkstra)" << endl;
     pair<vector<int>,double> test_djk3 = graph.Dijkstra(2334, 11051);
     vector<int> path3 = test_djk3.first;
     double distance3 = test_djk3.second;

    for (size_t i = 0; i < path3.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << path3.at(i) << " -> ";

        if (i == path3.size() - 1) {
            cout << " Destination Reached!" << endl;
            cout << "Flight Distance: " << distance3 << " km" <<  endl;
        }
    }

     cout << "Route from Portugal-> Doha (Dijkstra)" << endl;
     pair<vector<int>,double> test_djk4 = graph.Dijkstra(1638, 11051);
     vector<int> path4 = test_djk4.first;
     double distance4 = test_djk4.second;

    for (size_t i = 0; i < path4.size(); i++) {
        if (i == 0) {
            cout << "Starting Aiport: -> ";
        }
        cout << path4.at(i) << " -> ";

        if (i == path4.size() - 1) {
            cout << " Destination Reached!" << endl;
            cout << "Flight Distance: " << distance4 << " km" <<  endl;
        }
    }
}

TEST_CASE("picture (1)", "[weight=5]") {

    vector<Airport> airport_nodes;
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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

    FlightGraph graph = FlightGraph(airport_nodes, routes); 


    cs225::PNG worldMap;
    
    // DJIKSTRAS CODE //
    pair<vector<int>,double> test_djk = graph.Dijkstra(487, 4049);
     vector<int> shortest_path = test_djk.first;
     double distance = test_djk.second;




    worldMap.readFromFile("../tests/map.png");
    graph.pathVisualizer(worldMap, graph.GetVectorAirport(shortest_path), "../tests/testoutput.png");

}

TEST_CASE("picture (2)", "[weight=5]") {

    vector<Airport> airport_nodes;
    ifstream ifs{"../data/condensed_airport.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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

    FlightGraph graph = FlightGraph(airport_nodes, routes); 


    cs225::PNG worldMap;
    
    // DJIKSTRAS CODE //
    pair<vector<int>,double> test_djk = graph.Dijkstra(3484, 11051);
     vector<int> shortest_path = test_djk.first;
     double distance = test_djk.second;




    worldMap.readFromFile("../tests/map.png");
    graph.pathVisualizer(worldMap, graph.GetVectorAirport(shortest_path), "../tests/testoutput.png");

}

TEST_CASE("picture (3)", "[weight=5]") {

    vector<Airport> airport_nodes;
    ifstream ifs{"../entry/airports.csv"};
    for (string line; getline(ifs, line); line = "") {
        
        string row = line;
        vector<string> sections = GetSubstrs(line, ',');
        Airport to_add = Airport(stod(sections.at(6)), stod(sections.at(7)), sections.at(1), sections.at(4), stod(sections.at(0))); //stod converts string to double
        airport_nodes.push_back(to_add);
    }


    vector<Edge> routes;
    ifstream ifs_two{"../data/routes.csv"};
    
    for (string line; getline(ifs_two, line); line = "") {
        string row = line; 
        
        vector<string> sections = GetSubstrs(row, ',');
        if (sections.at(3) != "\\N" && sections.at(5) != "\\N" && sections.at(5) != "") {
            Edge to_add(sections.at(2), sections.at(4), stoi(sections.at(3)), stoi(sections.at(5)));
            //checking the route exists in data
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

    FlightGraph graph = FlightGraph(airport_nodes, routes); 


    cs225::PNG worldMap;
    
    // DJIKSTRAS CODE //
    pair<vector<int>,double> test_djk = graph.Dijkstra(893, 486);
     vector<int> shortest_path = test_djk.first;
     double distance = test_djk.second;




    worldMap.readFromFile("../tests/map.png");
    graph.pathVisualizer(worldMap, graph.GetVectorAirport(shortest_path), "../tests/testoutput.png");

}