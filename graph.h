#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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
    /** 
     * Returns -1 if lat/long are unknown, else returns distance in km
     * Distance calculated using Haversine formula (https://www.geeksforgeeks.org/haversine-formula-to-find-distance-between-two-points-on-a-sphere/)
    */
    double distance(const airportNode & airport) const {
        if (latitude_ == "\\N" || longitude_ == "\\N" || airport.latitude_ == "\\N" || airport.longitude_ == "\\N") {
            return -1;
        } else {
            double long1 = stod(longitude_);
            double lat1 = stod(latitude_);
            double long2 = stod(airport.longitude_);
            double lat2 = stod(airport.latitude_);

            double latDiff = (lat2 - lat1) * M_PI / 180.0;
            double longDiff = (long2 - long1) * M_PI / 180.0;
            lat1 = (lat1) * M_PI / 180.0;
            lat2 = (lat2) * M_PI / 180.0;

            double hav = pow(sin(latDiff / 2), 2) + pow(sin(longDiff / 2), 2) * cos(lat1) * cos(lat2);
            double radius = 6371;
            return 2 * radius * asin(sqrt(hav));
        }
    }
};

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
        int gid;
    private:
        vector<airportNode> adjList;
        
};