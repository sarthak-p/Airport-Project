 #pragma once 
 #include <vector>
 #include <unordered_map>
 #include <unordered_set>
 #include <queue>
 #include <deque>

using namespace std; 

class Flight {
    public:
        Flight();
        void airport(const string &filename, string line);
        void routes(const string &filename);

<<<<<<< HEAD
           //vector<string> dijkstra(const string &start, const string &end);
           //unordered_map<int, vector<edge>> routeMap;
           //unordered_map<string, int> airportIdMap;
=======
        std::vector<std::string> dijkstra(const string &start, const string &end);
        
    private:
        std::unordered_map<int, vector<edge>> routeMap;
        std::unordered_map<string, int> airportIdMap;
>>>>>>> 2b11d83dd62deb25106f52ce07af4abbe2054442

//     private:
//         string routes; 
//         string airports; 
//         vector<int> departure;
//         vector<int> arrival; 
<<<<<<< HEAD
// };
=======
};

struct edge {
    int destId;
    int sourceId;
    double distance;
};
>>>>>>> 2b11d83dd62deb25106f52ce07af4abbe2054442
