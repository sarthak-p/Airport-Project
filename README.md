# Trip Planner: Global Flight Simulator - Shortest Path & Centrality

## Team Members: Sarthak Patipati, Carter Smith, Sebastian Carrera, Isabel Alviar
- spati20
- carters3
- carrera9
- ialviar2

## How does our project work?
Our final project for CS225 parses real-world airport and route data from [OpenFlights.org](https://openflights.org) to create a custom graph structure for performing operations. This includes finding the shortest path between two airports using Depth-First Search (DFS) Traversal, calculating distance between airports and the total distance of the trip using Dijkstra's Algorithm, and measuring the connectedness of a given airport node using the Normalized Degree Centrality Algorithm. 

### Location of data
The raw data files we used from OpenFlights can be viewed by opening the data folder:
```cd data
cd data
```
Links to the datasets:
[airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat)
[routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat)

## How to build our program?
### To build the program, run:
```make -f Makefile.txt
make -f Makefile.txt
```
in the terminal.

The makefile will create a executable file named 'final'. Run this command in the terminal: 
```final
./final
```
## How to run and test our program?
### Steps:
- First, the user will be prompted to enter the IATA code of the airport of their departure location in all capitalized letters directly in the terminal.
For example, the IATA code of Chicago O’Hare International Airport is ORD. 
(insert picture)

- Next, the user will be prompted to input the IATA code of the airport of their desired arrival location in all capitalized letters directly in the terminal. 
(insert picture)

- Then, the user will be prompted to select which part of the trip planner they would like to use:
	- 0) Unique trip planner
	- 1) Shortest path (Dijkstra's Algorithm)
	- 2) Check connectedness of an airport (Normalized Degree Centrality Algorithm)
	- 3) End program

- Finally, the total distance in kilometers the trip would take and the shortest path between airports will be printed directly to the terminal. If there is not a route between two airports, the user will be told that there is no possible path in the 2,147,483,647 kilometers between all possible airport routes.

### Example result
(insert picture of an example later)
