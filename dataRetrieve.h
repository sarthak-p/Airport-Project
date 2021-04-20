#pragma once 


#include <vector>

using namespace std; 

class Data {
    public:
    Data();
    vector<int> getDepartures(const string & filename);
    vector<int> getArrivals(const string & filename); 

private:
    vector<int> departure; 
    vector<int> arrival; 
};