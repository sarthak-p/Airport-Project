//#include "flight.h"
#include"graph.h"
#include <vector>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std; 

// Flight::Flight() {
// }

void Flight::airport(const string & filename, string line) {
    ifstream airportFile(filename.c_str());
    string name, sname, country, ID, cID, lat, longi;
    string useless1, useless2, useless3;

    while (airportFile.good()) {
        getline(s, name, ',');
        getline(s, sname, ',');
        getline(s, country, ',');
        getline(s, ID, ',');
        getline(s, cID, ',');
        getline(s, lat, ',');
        getline(s, longi, ',');
        getline(s, useless1, ',');
        getline(s, useless2, ',');
        getline(s, useless3, '\n');
    }
    //vector fields
    airportNode entry(name, stoi(ID), iata, icao, stod(number2), stod(number3));
    }
    airportFile.close();
}


int main() {
    ifstream airportFile("airports.dat");
    string name, sname, country, ID, cID, lat, longi;
    string useless1, useless2, useless3;

    while(airportFile.good()) {
        getline(s, name, ',');
        getline(s, sname, ',');
        getline(s, country, ',');
        getline(s, ID, ',');
        getline(s, cID, ',');
        getline(s, lat, ',');
        getline(s, longi, ',');
        getline(s, useless1, ',');
        getline(s, useless2, ',');
        getline(s, useless3, '\n');
    }
    airportFile.close(); 
}
