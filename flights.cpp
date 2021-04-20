#include "flight.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std; 

Flight::Flight() {}; 

vector<int> Flight::flights(const string & filename) {
    ifstream file(filename);
    string str; 

    return departure;
}

vector<int> Flight::routes(const string &filename) {
    ifstream file(filename);
    string line; 
    if (file.is_open()) {
        istream_iterator<string> i(file);
        while (!file.eof()) {
            arrival.push_back(*i);
            ++i;
        }
    }
    return arrival;
}


