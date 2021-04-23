<<<<<<< HEAD
#pragma once 
#include <vector>
=======
// #pragma once 
// #include <vector>
// #include <unordered_map>
>>>>>>> 167895a7fa1edeb04746fd825305c17921c43573

using namespace std; 

class Flight {
    public:
        Flight();
        void airport(const string &filename, string line);
        void routes(const string &filename);

<<<<<<< HEAD
    private:
        string routes; 
        string airports; 
        vector<int> departure;
        vector<int> arrival; 
};
=======
           //vector<string> dijkstra(const string &start, const string &end);
           //unordered_map<int, vector<edge>> routeMap;
           //unordered_map<string, int> airportIdMap;

//     private:
//         string routes; 
//         string airports; 
//         vector<int> departure;
//         vector<int> arrival; 
// };
>>>>>>> 167895a7fa1edeb04746fd825305c17921c43573
