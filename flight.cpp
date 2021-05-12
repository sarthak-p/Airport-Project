#include "flight.h"
#include "readFromFile.cpp"
#include"graph.h"
#include "main.cpp"

using namespace std;

// Flight::Flight() {
// }

/** 
 * Dijkstra's algorithm for finding the shortest path between two airports
 * */ 
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
 * Performs a DFS traversal of the whole graph beginning from the start airport 
 * */
void Flight::DFS(const string & start, vector<route> paths) {

//if start location not found in map then throw error 
  if (!airportIdMap.count(start)) {
    cout << "Error: Starting Location Not Found" << endl; 
    return; 
  }

  //set current node to start ID, this is our "root"
  int current = airportIdMap[start]; // example ID for JFK is 3797

  //create a temp adjacency list (2D vector) that holds connected edge info 
  vector<vector<int>> temp_adj; 
  for (auto & i : paths) {
    temp_adj[airportIdMap[i.source]].push_back(airportIdMap[i.destination]);
    temp_adj[airportIdMap[i.destination]].push_back(airportIdMap[i.source]); 
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
 * Performs a DFS traversal of the graph from start to end airport and outputs the path 
 * */
vector<string> Flight::DFS2(const string &start, const string &end, vector<route> paths, map<int, string> convertIndex) {

  if (airportIdMap.count(start) == 0) {
    cout << "Error: Starting Location Not Found" << endl;
  }

  if (airportIdMap.count(end) == 0) {
    cout << "Error: Destination Location Not Found" << endl;
  }

  if (start == end) {
    cout << "You are already at your Destination :-)" << endl;
  }

//beginning our final nodes to know where to stop 
  int begin = airportIdMap[start]; 
  int final = airportIdMap[end]; 

//temporary adjacency list to hold edge data
  vector<vector<int>> temp_adj;
//pushing the edge data in to the adjacency list
  for (auto &i : paths) {
    temp_adj[airportIdMap[i.source]].push_back(airportIdMap[i.destination]);
    temp_adj[airportIdMap[i.destination]].push_back(airportIdMap[i.source]);
  }

  //bool vector to keep track of visited airports 
  vector<bool> visited(14110);
  for (int i = 0; i < 14110; i++) {
    visited[i] = false;
  }

  //vector to keep track of our visited airports between start and end 
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
    //stop when current is the same as end airport 
    if (current == final) {
      break; 
    }
  }

  //creating a vector of string that converts int code to IATA
  vector<string>converted; 
  for (int i : track) {
    converted.push_back(convertIndex[i]); 
  }
  //returning the vector which contains the path from start to end 
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
