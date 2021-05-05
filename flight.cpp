//#include "flight.h"
#include"graph.h"
#include <vector>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std; 

// Flight::Flight() {
// }

vector<string> Flight::dijkstra(const string &start, const string &end) { 
    // Error messages 
    if (!airportIdMap.count(start)) {
        cout << "Error: Starting location not found" << endl;
    }
    if (!airportIdMap.count(end)) {
        cout << "Error: Ending location not found" << endl;
    }
    if (start == end) {
        cout << "Error: Starting and ending location are the same" << endl;
    }

    int startId = airportIdMap[start]; // example ID = ORD is O'Hare
    int endId = nameToIdMap[end];
    
    // priority_queue<pair<int, int>> pq;
    priority_queue<pair<double, edge>> pq;
    
    // Gets vector with all connecting routes with an airport
    vector<edge> connectingEdges = routeMap[startId];
    processed.insert(startId);
}


