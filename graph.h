#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct airportNode {
    string name, code;
    double latitude, longitude;
    airportNode * next;
};

struct adjRoutes {
    airportNode * first;
};

class Graph {
    public:
        Graph();
        void addEdge(airportNode a, airportNode b);
        void addNode(airportNode input);
        void removeNode(airportNode )
    private:
        vector<adjRoutes> adjList;

};