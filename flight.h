#pragma once 

#include <vector>

using namespace std; 

class Flight {
    public:
        Flight();
        vector<int> getAirports(const string &filename);
        vector<int> getRoutes(const string &filename);

    private:
        string routes; 
        string airports; 
        vector<int> departure;
        vector<int> arrival; 
};