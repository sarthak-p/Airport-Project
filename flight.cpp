#include "flight.h"
#include "readFromFile.cpp"
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
 * Performs a DFS traversal of the whole graph 
 * Param: start: start point, path: vector of edges 
 * For example, start = JFK is John. F Kennedy Airport, NY  
 * */

void Flight::DFS(const string & start, vector<edge> paths) {

  if (!airportIdMap.count(start)) {
    cout << "Error: Starting Location Not Found" << endl; 
  }

  int current = airportIdMap[start]; // example ID for JFK is 3797

  //create a temp adjacency list that holds connected edge info 
  vector<vector<int>> temp_adj; 
  for (auto & i : paths) {
    temp_adj[i.sourceId].push_back(i.destId);
    temp_adj[i.destId].push_back(i.sourceId); 
  }

  //bool vector to keep track of visited nodes 
  vector<bool> visited(14110);
  for (int i = 0; i < 14110; i++) {
    visited[i] = false; 
  }

  //stack to hold nodes 
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

/**
 * Performs a DFS traversal of the graph from start to end point 
 * Param: start: start point, end: end point, paths: vector of edges 
 * */
vector<string> Flight::DFS2(const string &start, const string &end, vector<edge> paths) {

  if (airportIdMap.count(start) == 0) {
    cout << "Error: Starting Location Not Found" << endl;
  }

  if (airportIdMap.count(end) == 0) {
    cout << "Error: Destination Location Not Found" << endl;
  }

  if (start == end) {
    cout << "You are already at your Destination :-)" << endl;
  }

  int begin = airportIdMap[start]; 
  int final = airportIdMap[end]; 

  vector<vector<int>> temp_adj;
  for (auto & i : paths) {
    temp_adj[i.sourceId].push_back(i.destId);
    temp_adj[i.destId].push_back(i.sourceId);
  }

  //bool vector to keep track of visited nodes
  vector<bool> visited(14110);
  for (int i = 0; i < 14110; i++) {
    visited[i] = false;
  }

  //vector to keep track of our visited points
  vector<int> track(14110);
  track[begin] = begin;
  int current = begin;

  //stack to add nodes 
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
        track.push_back(code);
      }
    }
    if (current == final) {
      break; 
    }
  }
  vector<string>converted; 
  for (int i : track) {
    converted.push_back(idConvertMap[i]); 
  }
  return converted; 
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
