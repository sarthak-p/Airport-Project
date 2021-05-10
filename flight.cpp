#include "flight.h"
#include"graph.h"

using namespace std;

// Flight::Flight() {
// }

std::vector<std::string> Flight::dijkstra(const string &start, const string &end) { 
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

    int startId = airportIdMap[start]; //example ID = ORD is O'Hare, Chicago 
    int endId = airportIdMap[end];
    
    // priority_queue<pair<int, int>> pq;
    priority_queue<pair<double, edge>> pq;
    unordered_set<int> processed;
    unordered_map<int, int> parentOfId;
    
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
       cout << "No route found." << endl;
    }
    
    // Traverse parents in deque to put resulting path
    deque<int> resulting_path;
    int parent = endId;
    while (parent != startId) {
      resulting_path.push_front(parent);
      parent = parentOfId[parent];
    }
    resulting_path.push_front(parent);
    
    // Need to output path
}

/**
 * Performs a DFS traversal of the graph 
 * Param: ID of the Airport where traversal begins
 * For example, start = JFK is John. F Kennedy Airport, NY  
 * */
void Flight::DFS(const string & start, vector<edge> paths) {

  //check if given airport exists in our map  
  if (airportIdMap.count(start) == 0) {
    cout << "Error: Starting Location Not Found" << endl;
  }

  //our root or the chosen start point 
  int current = airportIdMap[start]; // example ID = 3797 is JFK

  //create a temp adjacency list that holds connected edge info 
  vector<vector<int>> temp_adj; 

  //populate our adjacency list using info from paths 
  for (auto & i : paths) {
    temp_adj[i.sourceId].push_back(i.destId);
    temp_adj[i.destId].push_back(i.sourceId);
  }

  //bool vector to keep track of visited nodes 
  vector<bool> visited(14110);
  for (int i = 0; i < 14110; i++) {
    visited[i] = false;
  }

  //make a stack and push our root while marking it as visited 
  stack<int> reference; 
  reference.push(current);
  visited[current] = true; 
  
  //perform DFS 
  while (!reference.empty()) {
    current = reference.top(); 
    reference.pop(); 

    if (visited[current] == false) {
      visited[current] = true; 
    }

    for (int code : temp_adj[current]) {
      if (visited[code] == false) {
        reference.push(code);
      }
    }
  }
}
/*
void Flight::airport(const string & filename, string line) {
    ifstream airportFile(filename.c_str());
    string name, sname, country, ID, cID;
    string useless1, useless2, useless3, stringLat, stringLong;

    while (airportFile.good()) {
        getline(s, name, ',');
        getline(s, sname, ',');
        getline(s, country, ',');
        getline(s, ID, ',');
        getline(s, cID, ',');
        getline(s, stringLat, ',');
        getline(s, stringLong, ',');
        getline(s, useless1, ',');
        getline(s, useless2, ',');
        getline(s, useless3, '\n');
    }

    //vector fields
    airportNode entry(name, stoi(ID), stod(stringLat), stod(stringLong));
    airportFile.close();
}
*/

