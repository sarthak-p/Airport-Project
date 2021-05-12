#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "graph.h"
#include <map>

using namespace std;

class adjMatrix {
    public:
    /** 
     * constructor that builds the adjacency matrix
     * */ 
      adjMatrix(std::vector<airportNode> &airportVector, std::vector<route> &routeVector) {
        // Generate the Vlen by Vlen square adjMatrix basework, sets every cost to 0:
        int Vlen = airportVector.size();
        matrix = new int*[Vlen];
        for (int i =0; i < Vlen; i++) {
          matrix[i] = new int[Vlen];
          for (int j =0; j < Vlen; j++) {
            matrix[i][j] = 0;
          }
        }
        for (int i =0; i < Vlen; i++) {
          matrix[i][i] = -1;
        }
        
        // Make a map of airport names to index in airportVector
        // Testing var
        int test = 20;
        for (int i = 0; i < Vlen; i++) {
          nameToIndex[std::string(airportVector[i].code_)] = i;
          indexToName[i] = std::string(airportVector[i].code_);
          if (test < 20) {
            test++;
            std::cout << "sample code:" << airportVector[i].code_ << std::endl;
            std::cout << "sample lookup:" << nameToIndex[airportVector[i].code_] << std::endl;
          }
        }
           
        int Rlen = routeVector.size();   
        for (int i = 0; i < Rlen; i++) {
          route subject = routeVector[i];
          string start = subject.source;
          string end = subject.destination;
          //std::cout << "Sample start: " << start << std::endl;
          int row = nameToIndex["\"" + start + "\""];
          int column = nameToIndex["\"" + end + "\""];
          subject.distance = airportVector[row].dist(airportVector[column]);
          matrix[row][column] = subject.distance; // Calculate distance       
        }

      }
       
        int** matrix;
        std::map<std::string, int> nameToIndex;
        std::map<int, std::string> indexToName;
        
};