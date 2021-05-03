#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "graph.h"

using namespace std;
/*
Credit to course staff for providing a basic template for this. 
Provided sample was adapted for our specific use case.
*/

vector<route> readToVector(const string & routeFile) {
    vector<route> result;
    string line, colVal;
    ifstream file;
    file.open(routeFile);

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream s(line);
            while (s >> colVal) {
                break;
            }
        }
    } else {
        throw runtime_error("Opening route file was unsuccesful");
    }

    file.close();
    return result;
}

/**
 * @param input stringstream for CSV airport data,
 * @return airportNode with given info
 */ 
airportNode readAirportHelp(stringstream &input) {
    string colVal;
    vector<string> temp;
    while (getline(input, colVal, ',')) {
        temp.push_back(colVal);
    }
    airportNode result(temp[1], temp[4], temp[2], temp[3], temp[6], temp[7]); 
    return result;
}

vector<airportNode> readAirports(const string & airportFile) {
    vector<airportNode> result;
    string line;
    ifstream file;
    file.open(airportFile);

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream s(line);
            result.push_back(readAirportHelp(s));
        }
    } else {
        throw runtime_error("Opening airport file was unsuccesful");
    }

    file.close();
    return result;
}

