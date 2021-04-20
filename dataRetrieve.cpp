#include "dataRetrieve.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std; 

Data::Data() {}; 

vector<int> Data::getDeparture(const string & filename) {
    ifstream file(filename);

    if (file.is_open()) {
        istream_iterator<string> i(file);
        while (!file.eof()) {
            departure.push_back(*iter);
            ++iter;
        }
    }
    return departure;
}

vector<int> Data::getDeparture(const string &filename) {
    ifstream file(filename);

    if (file.is_open()) {
        istream_iterator<string> i(file);
        while (!file.eof()) {
            departure.push_back(*iter);
            ++iter;
        }
    }
    return departure;
}
