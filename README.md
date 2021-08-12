# Trip Planner: Global Flight Simulator - Shortest Path & Centrality

![](/images/airport-demo.gif)

## How does the project work?
The project parses real-world airport and route data from [OpenFlights.org](https://openflights.org) to create a custom graph structure for performing operations. This includes finding the shortest path between two airports using Depth-First Search (DFS) Traversal, calculating distance between airports and the total distance of the trip using Dijkstra's Algorithm, and measuring the connectedness of a given airport node using the Normalized Degree Centrality Algorithm. 

### Location of data
The raw data files used from OpenFlights can be viewed by opening the data folder:
```cd data
cd data
```
Links to the datasets:
[airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat)
[routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat)

## How to build the program?
### To build the program, run:
```
g++ main.cpp centrality.cpp -o main
```
in the terminal.

This will create a executable file named 'main'. Run this command in the terminal:
```
./main
```
### To build the testing suite, run:
```
make -f Makefile.txt test
```
in the terminal.
This will create an executable named 'test'. Run this command in the terminal:
```
./test
```
## How to run and test the program?
### Steps
- First, the user will be prompted to enter the IATA code of the airport of their departure location in all capitalized letters directly in the terminal.
For example, the IATA code of Chicago O’Hare International Airport is ORD. 

- Next, the user will be prompted to input the IATA code of the airport of their desired arrival location in all capitalized letters directly in the terminal. 

- Then, the user will be prompted to select which part of the trip planner they would like to use:
	- 0: Unique trip planner (DFS)
	- 1: Shortest path (Dijkstra's Algorithm)
	- 2: Check connectedness of an airport (Normalized Degree Centrality Algorithm)
	- 3: End program

- Finally, based on the user's choice, the following information will be printed directly in the terminal:
	- If the user selects 0: Unique Trip Planner
		- A list with all the possible airport codes 
	- If the user selects 1: Shortest Path (Dijkstra)
		- The total distance in kilometers the shortest trip would take and the shortest path between two airports
	- If the user selects 2: Connectedness (Centrality)
		- The calculated normal degree centrality for a single airport

### Examples:
#### User is prompted to select from trip menu
![Picture](/images/projectMenu.png)
#### 1: Shortest Path (Dijsktra)
![Picture](/images/dijkstra.png)
#### 2: Connectedness (Centrality)
![Picture](/images/degreeCentrality.png)

### Presentation Link: https://youtu.be/1_MHqG7orV4

### Demo Video Link: https://youtu.be/0FIJP5yoOXI


