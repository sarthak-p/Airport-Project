#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Using IATA codes for airports
 * Construct node with strings for lat/long, convert to double if valid
*/
struct airportNode {
    string name_, code_, city_, country_, latitude_, longitude_;
    //vector<route> edgeList;
    airportNode();
    airportNode(string name, string code, string city, string country, string lat, string longi): name_(name), code_(code), city_(city), country_(country), latitude_(lat), longitude_(longi) {}
};

// To-do: Make distance function for finding distance
struct route {
    string source, destination;
    double distance;
    route(string src, string dest): source(src), destination(dest) {}
};

class Graph {
    public:
        Graph();
        void addEdge(route edge);
        void removeEdge(route edge);
        void addNode(airportNode node);
        void removeNode(airportNode node);
        void print();
        vector<route> getAdj(airportNode node);
    private:
        vector<airportNode> adjList;
};