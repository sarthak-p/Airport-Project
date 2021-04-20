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
    }
};

struct route {
    airportNode source, destination;
    route(airportNode src, airportNode dest): source(src), destination(dest) {}
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