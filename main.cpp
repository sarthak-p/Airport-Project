#include <iostream>
#include "graph.h"
#include "readFromFile.cpp"
//#include "adjMatrix.h"
//#include "dijkstra.h"

void sebby(); ////comment out to run DFS
// int main() {
//     std::cout << "This is our main file" << std::endl;
//     sebby(); //comment out to run DFS
//     return 0; //comment out to run DFS
    
//     //original main:
//     std::cout << "This is our main file" << std::endl;
//     std::vector<airportNode> airportVector = readAirports("data/airports.dat");
//     std::cout << "first airportNode: " << airportVector[0].name_ << std::endl;
//     std::cout << "second airportNode: " << airportVector[1].name_ << std::endl;
//     std::cout << "distance: " << airportVector[0].dist(airportVector[1]) << std::endl;

//     std::vector<route> routeVector = readRoutes("data/routes.dat");
//     std::cout << "Route #1 source: " << routeVector[0].source << std::endl;
//     std::cout << "Route #2 destination: " << routeVector[0].destination << std::endl;

//     return 0;
// }


/**
void graph_test() {
    vector<Airportnode> a = readAirports(); 
    vector<route> b = readRoutes(); 
    Graph graph = Graph(a, b); 
    graph.print(); 
}
**/
//comment out to run DFS
// void sebby() {
//   std::cout << "This is SEBBY" << std::endl;
//   std::vector<airportNode> airportVector = readAirports("data/airports.dat");
//   std::cout << "Airports read from file" << std::endl;
//   std::cout << "first airportNode: " << airportVector[0].name_ << std::endl;
//   std::cout << "second airportNode: " << airportVector[1].name_ << std::endl;
  
//   std::vector<route> routeVector = readRoutes("data/routes.dat");
//   route sampleRoute = routeVector[17314];
  
//   std::cout << "route vector size: " << routeVector.size() << std::endl;
  
//   adjMatrix myMatrix(airportVector, routeVector);
//   std::cout << "sample of AdjMatrix (2810, 2832): " << myMatrix.matrix[2810][2832] << std::endl;
  //myMatrix.nameToIndex["\"ORD\""]
  /**for (int i =0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      std::cout << "sample of AdjMatrix: " << myMatrix.matrix[i][j] << std::endl;
    }
  }**/
  
  
  
//   make sample graph:
//   Graph sG = Graph();
//   std::cout << "Graph id: " << sG.gid << std::endl;
//   sG.addNode(airportVector[0]);
//   sG.addNode(airportVector[1]);
//   sG.addEdge(sampleRoute);
  
//   sG.print();
  
  
  //dijkstra("GKA", "MAG");
  
//}