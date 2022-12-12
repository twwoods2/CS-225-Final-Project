# CS-225-Final-Project
------------------------------------------------------------------------------------
Taigue Woods, Dylan Huey, Ankit Saxena, Jay Wagh
-------------------------------------------------------------------------------------
Github Organization
-------------------------------------------------------------------------------------
Location of Code within Repository: 

Documents - Team Proposal & Team Contract documents are contained in this file.

Data - Contains all data cleaned and raw that is retrieved from https://openflights.org/data.html.

Entry - Contains where the user will input information for the program to solve and output the results. The containers necessary for running this program will be main.cpp and output.png will be used to print the user's results. 

Lib - Contains provided code from the CS 225 class, such as the lodepng files, HSLA pixel object, and PNG object.

Src - Contains the Airport class, Edge class, and our graph class. These are responsible for representing our data and using for operations. Also, contains our
utilities container which is used for parsing through csv files.

Tests - Contains the tests that we ran as we developed our code. 
-------------------------------------------------------------------------------------
Written Report - See directory; in the container labeled Result.md.

Presentation - (Insert Youtube Link)
-------------------------------------------------------------------------------------
Running Instructions
-------------------------------------------------------------------------------------
Steps For Running Code: 

1. Ensure that the correct environment is set up on computer. Must contain an existing Dockerfile that compiles with at least using CXX_FLAGS=-std=c++20. Instructions for setting up virtual machine can be found at https://courses.engr.illinois.edu/cs225/fa2022/resources/own-machine/.

2. Clone the repository by downloading it manually and placing it in container or by cloning the repository into the workable container.

3. Once in container with DockerFile, change the directory using
```c++
cd
```

4. Once in base directory, use 
```c++
mkdir build
cd build
```

5. For making the MakeFile, we chose to use Cmake, so execute the line 

```c++
cmake .. 
```

6. The Cmake files will create a directory to compile and execute containers that are 
found as entries, so using 
```c++ 
make 
``` 
will allow you to compile the code

7a. From here, you will be able to input your starting point and destination by using 
```c++
./main
``` 
Running the main container will prompt you for your starting point and destination.

7b. In order to run our provided test cases, you can execute 
```c++
./test
```
This will allow you to see observe and see that our test cases function accordingly.




