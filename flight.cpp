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

void Flight::dijkstra(const string &start, const string &end) { 
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
    
    // Intial case
    for (size_t i = 0; i < connectingEdges.size(); ++i) {
      pq.push(pair<double, edge>(-1 * connectingEdges[i].distance, connectingEdges[i]));
    }

    // Loop until shortest path or no path is found
    int nextId = -1;
    double nextDistance;
    while (nextId != endId && !pq.empty()) {
      nextDistance = pq.top().first;
      nextId = pq.top().second.destId;
      edge temp = pq.top().second;
      pq.pop();

      if (processed.find(nextId) == processed.end()) {
        parentOfId.insert(pair<int, int>(temp.destId, temp.sourceId));
        connectingEdges = routeMap[nextId];
        for (size_t i = 0; i < connectingEdges.size(); ++i) {
          pq.push(pair<double, edge>(-1*connectingEdges[i].distance + nextDistance, connectingEdges[i]));
        }
          processed.insert(nextId);
        }
    }
    
    // If no route is found betwen airports
    if (nextId != endId && pq.empty()) {
      throw NO_ROUTE_FOUND;
    }
    
    // Traverse parents in deque to put resulting path
    deque<int> resulting_path;
    int parent = endId;
    while (parent != startId) {
      resulting_path.push_front(parent);
      parent = parentOfId[parent];
    }
    resulting_path.push_front(parent);
    
    // Creates string itinerary to be returned
    vector<string> itinerary;
    makeItinerary(path, itinerary);
    return itinerary;
  
}


