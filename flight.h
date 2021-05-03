// #pragma once 
// #include <vector>
// #include <unordered_map>

using namespace std; 

class Flight {
    public:
        Flight();
        void airport(const string &filename, string line);
        void routes(const string &filename);

           //vector<string> dijkstra(const string &start, const string &end);
           //unordered_map<int, vector<edge>> routeMap;
           //unordered_map<string, int> airportIdMap;

//     private:
//         string routes; 
//         string airports; 
//         vector<int> departure;
//         vector<int> arrival; 
// };
