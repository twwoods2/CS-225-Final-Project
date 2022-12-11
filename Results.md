Overview of algorithms:

We implemented two main algorithms as well as a function that writes our results from 
the two main algorithms onto a PNG file. Our two main graph algorithms are dijkstra's algorithm
along with a breadth first search. 

Breadth First Search (BFS) - For this algorithm, we wanted to optimize our runtime for the time complexity. In 
designing our Flightgraph class, we wanted to construct an adjacency list which stores the neighbors of airports 
found through the routes dataset. Implementing BFS becomes more optimal in the case of using an adjacency list 
since our runtime equates to O(n + m), n being the nodes and m being the edges. This runtime is signficantly 
better than implmenting an adjacency matrix because the runtime equates to O(n^2), n being the nodes. In terms of 
testing whether this algorithm works, we provide small-scaled datasets to test the algorithm because testing on 
the large-scale dataset usually takes too much time and is impractical for general testing. Large scale tests are 
also included for this algorithm as well.

Dijkstra's Algorithm - For our implementation of dijkstra's algorithm, we used a priority queue (min-heap) for solving
the shortest path between two nodes. In terms of testing, dijkstra's algorithm takes quite awhile to run on our large-scale
dataset, so we had to again make smaller dataset for testing the correctness of this algorithm. We also paid attention to our 
distance(kilometers) output from the shortest path which allowed us to evaluate our result with real world data. 

PNG file output - we used the provided code for PNG class that we had from the machine problems that we used. With the 
provided code, it didn't take much to produce a graphical output. One thing that we had to figure out was translating 
the latitude and longitude inputs of the airports and place them on the png output. In terms of testing, we made a small scale and 
large scale test which had the png output be drawn from the provided inputs and datasets.

Answer for leading question:

We were able to achieve upon which what we outlined in our leading question. Ultimately we wanted a program that 
allows a user to figure out what's the shortest path between two points, their destination and endpoint. Our program 
is capable of not only finding the shortest path for the user, but also plotting the path onto a PNG file. One thing that 
we discovered was that we definitely needed to clean our airports dataset as there were local airports and other airports that 
would have no routes. For these, we had to not only clean our data properly but also ensure that we were not creating 
invalid airports to start at.
