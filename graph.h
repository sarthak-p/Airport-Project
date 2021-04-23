#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct airportNode {
    string name, code;
    double latitude, longitude;
    vector<route> edgeList;
    airportNode(string n, string c, double lat, double longi, vector<route> edges): name(n), code(c), latitude(lat), longitude(longi) { 
        for (auto destination : edges) {
            edgeList.push_back(destination);
        }
    } // extra } error here - why? 
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
    private:
        vector<airportNode> adjList;
};