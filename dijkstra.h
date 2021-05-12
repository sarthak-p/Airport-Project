// C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph.
#include <stdio.h>
#include <limits.h>
#include <iostream>

// Number of vertices (airports) in the graph
#define V 7698
#include "adjMatrix.h"

/**
 * A utility function to find the vertex with minimum distance value, from the set of vertices
 * not yet included in shortest path tree
 * */ 
int minDistance(int dist[], bool sptSet[]) {
  // Initialize min value
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
  if (sptSet[v] == false && dist[v] <= min) {
    min = dist[v], min_index = v;
  }

  return min_index;
}

/**
 * prints shortest path from source to j using parent array
 * */ 
void printPath(int parent[], int j, int srcc, adjMatrix myMatrix) {
  
  // Base Case : If j is source
  if (j == srcc) {
    return;
  }
  
  auto hi = parent[j];
  printPath(parent, hi, srcc, myMatrix);
  printf("%s ", myMatrix.indexToName[j].c_str());
}

/**
 * A utility function to print the constructed distance array where all the printing happens!
 * */ 
int printSolution(int dist[], int parent[], int destIndex, int src, adjMatrix myMatrix) {
  //printf("Vertex\t Distance\tPath");
  int i = destIndex;
  //for (int i = 1; i < V; i++) {
  std::cout << "-----------------------------------------------------------------------------------" << std::endl;
  std::cout << "Shortest Total Distance: " << dist[i] << " kilometers" << std::endl;
  //std::cout << "test" << std::endl;
  std::cout << "Shortest Airport Path: ";
  printf(myMatrix.indexToName[src].c_str(), myMatrix.indexToName[i].c_str(), dist[i], myMatrix.indexToName[src].c_str());
  flush(std::cout);
  // std::cout << "test 2" << std::endl;
  printPath(parent, i, src, myMatrix);
  flush(std::cout);
  std::cout << "\nSuccess: There Is Not an ";
  flush(std::cout);
  return -1; 
}

/**
 * Funtion that implements Dijkstra's single source shortest path algorithm for a graph
 * represented using adjacency matrix representation
 * */ 
void dijkstra(int** graph, int src, int destIndex, adjMatrix myMatrix) {
  // The output array. dist[i] will hold the shortest distance from src to i
  int dist[V];

  // sptSet[i] will true if vertex i is included / in shortest path tree or shortest distance
  // from src to i is finalized
  bool sptSet[V];

  // Parent array to store shortest path tree
  int parent[V];

  // Initialize all distances as INFINITE and stpSet[] as false
  for (int i = 0; i < V; i++) {
    parent[0] = -1;
    dist[i] = INT_MAX;
    sptSet[i] = false;
  }

  // Distance of source vertex from itself is always 0
  dist[src] = 0;

  // Find shortest path for all vertices
  for (int count = 0; count < V - 1; count++) {

    // Pick the minimum distance vertex from the set of vertices not yet processed.
    // u is always equal to src in first iteration.
    int u = minDistance(dist, sptSet);

    // Mark the picked vertex as processed
    sptSet[u] = true;

    // Update dist value of the adjacent vertices of the picked vertex.
    for (int v = 0; v < V; v++)

    // Update dist[v] only if is not in sptSet, there is an edge from u to v,
    // and total weight of path from src to v through u is smaller than current value of dist[v]
    if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
      parent[v] = u;
      dist[v] = dist[u] + graph[u][v];
    }
}

//Print the constructed distance array
printSolution(dist, parent, destIndex, src, myMatrix);
 //printSolution(dist, V, parent, destIndex, src);
}
