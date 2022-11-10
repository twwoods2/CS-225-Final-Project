## Leading Question 
For our project, we want to implement a flight program that allows a user to input their closest airport and an airport that they choose to travel to, and be able to route them the shortest path from their starting location to the ending location. The given datasets that we are working with are the ones provided from the https://openflights.org/data.html website. These datasets provides us the location (latitude and longitude) of Airports, their IDs, and their outgoing and ingoing routes. We will use this data to build a graph where the nodes are airports and the routes are edges. From here, we will implement Dijkstra's algorithm to find the shortest path from the starting airport and the ending airport. Additionally, we will also draw a path between the airports that are in the shortest path onto a PNG file.
## Dataset Acquisition
   How we acquire our data will be in a two-step process. First we have our airports.csv file which is formated in the fashion of [Airport ID, Name, City, Country, IATA, ICAO, Latitude, Longitude, Altitude, Time Zone, DST, Tz type, and Source]. This information on each individual aiport will allow us to create our nodes. Then we'll have to implement the edges which will come out of using the routes.csv which has of the format of [Airline, Airline ID, Source airport, Source airport ID, Destination airport, Destination airport ID, Codeshare, Stops, Equipment]. For the simplicity of performing our goal, we will only be concerned with the source airport and destination airport. These two data values will be used to connect airports with ingoing and outgoing flights.
## Data Format
   The two datasets that we'll be using are the airport.csv and routes.csv. The airports.csv contains 141 airports, and the routes.csv contains 67,663 connections between airports.We believe this database should not contain any problematic data values as the creators fund and revise the database frequently. As addressed earlier, we want to create nodes from the airports.csv file. This will allow us to enough information to create nodes which will represent airports. Data values that will be used will be the Airport ID, Name, City, Country, IATA, ICAO, Latitude, and Longitude. Additionally information for establishing the edges will be from the routes.csv which will only require the Source Airport, Source Airport ID, Destination airport, and Destination airport ID.
## Data Correction
   With having pretty massive datasets, we want to start this project by creating the nodes are airports which shouldn't be a difficult or hefty process. There are a total of 141 aiports in the aiports.csv. How we would parse these values would be using a stream to go through each line, and fragment the only values that we are concerned with. From these values, we're able to construct our nodes. Then, we will use the similar process of establishing connections with the routes.csv file. Parsing each line and fragmenting the data values that we're interested in will be our way that we construct edges.

## Data Storage
   We plan to store the information about aiports as nodes and their destinations as edges. Both nodes and edges will contain each their own class that they be used to be stored in. Both classes will be used to implment a graph class which will include both classes being used for Dijkstra's algorithm. Our estimated runtime for our algorithm would be O(V + Elog(V)) assuming that we use a min-heap.

## Algorithm 
   For solving our problem, we will primarly be using Dijkstra's algorithm to find the shortest paths between two paths. The runtime for this algorithm can vary as the worst case is O(V + Elog(V)). The average case for time complexity for this algorithm is O(E + Vlog(E/v)log(V). Both cases would use a binary heap in order to achieve this runtime. The inputs required for this algorithm are simply two nodes. In this case, we want to find shortest path between the starting airport and the destination airport so we will ask the user for the input of their starting airport and destination airport.
    
   The construction of our graph shouldn't take more than O(n + m) runtime with n being the number of airports and m being the number of nodes. Inputs will be provided from both csv files.
    
   Restraints of memory will be how much data that we will be storing for our graph to function. For Dijkstra's algorithm, we will be storing a path as we determine the shortest path. Memory optimization will soley depend on how we choose to implement Dijkstra's algorithm with whichever data structure.

## Timeline
   Week 1 (11/6-11/13) work on components to build graph such as nodes and edges; heaps will be implemented when we start Dijkstra's algorithm. 
    
   Week 2 (11/13-11/20) work on compiling the program such as constructing a makefile and begin to work on building repository directory for running our program 
    
   Week 3 (Fall Break) No directed objective but our team will plan to increment tests and build the image for representing our shortest path.
    
   Week 4 (11/27-12/3) Implement and test Dijkstra's algorithm. Map path accordingly. Wrap up tests. Write up presentation.
