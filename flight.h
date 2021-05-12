#pragma once 
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <deque>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include <stack>
#include "adjMatrix.h"

using namespace std;

struct edge {
    int destId;
    int sourceId;
    double distance;
};

class Flight {
    public:
        Flight();
        void airport(const string &filename, string line);
        void routes(const string &filename);
        std::vector<std::string> dijkstra(const string &start, const string &end);
        void DFS(const string & start, vector<route> paths);
        vector<string>DFS2(const string & start, const string & end, vector<route> paths);

    private:
        std::unordered_map<int, vector<edge>> routeMap;
        std::unordered_map<string, int> airportIdMap;
        std::unordered_map<int, string> idConvertMap; 

//     private:
//         string routes; 
//         string airports; 
//         vector<int> departure;
//         vector<int> arrival; 
// };
};

