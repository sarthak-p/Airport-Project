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
        adjMatrix(std::vector<airportNode> &airportVector, std::vector<route> &routeVector) {
            //generate the Vlen by Vlen square adjMatrix basework, sets every cost to -1:
            int Vlen = airportVector.size();
            matrix = new int*[Vlen];
            for (int i =0; i < Vlen; i++) {
                matrix[i] = new int[Vlen];
                for (int j =0; j < Vlen; j++) {
                    matrix[i][j] = 0;
                }
            }
           
            //make a map of airport names to index in airportVector
           
            //testing var
            int lol1 = 20;
            for(int i = 0; i < Vlen; i++) {
                nameToIndex[std::string(airportVector[i].code_)] = i;
                if(lol1 < 20) {
                    lol1++;
                   
                    std::cout << "sample code:" << airportVector[i].code_ << std::endl;
                    std::cout << "sample lookup:" << nameToIndex[airportVector[i].code_] << std::endl;
                }
            }
           
            /**
           
           
            string myS2 = std::string("\"VEY\"");
            if ( nameToIndex.find(myS2) == nameToIndex.end() ) {
              std::cout << "not found" << nameToIndex[myS2] << std::endl;
            } else {
              std::cout << "found" << nameToIndex[myS2] << std::endl;
            }
           
            for(std::map<string,int>::iterator it = nameToIndex.begin(); it != nameToIndex.end(); ++it) {
              std::cout << "Key: " << it->first << std::endl;
            }**/
           
           
            //testing var
            int lol = 10;
           
            int Rlen = routeVector.size();
           
            for(int i = 0; i < Rlen; i++) {
                route subject = routeVector[i];
                string start = subject.source;
                string end = subject.destination;
                //std::cout << "sample start: " << start << std::endl;
                int row = nameToIndex["\"" + start + "\""];
                int column = nameToIndex["\"" + end + "\""];
                subject.distance = airportVector[row].dist(airportVector[column]);
                matrix[row][column] = subject.distance;
                /**
                if (subject.distance != 0) {
                  std::cout << "dist: " << subject.distance << std::endl;
                }**/
               
                //std::cout << "info: " << subject.source << std::endl;
               
                //route vector always has 0
               
                if(lol < 10) {
                    lol++;
                    std::cout << "sample row column:" << row << " , " << column << std::endl;
                }
               
            }
        };
       
        int** matrix;
        std::map<std::string, int> nameToIndex;
};