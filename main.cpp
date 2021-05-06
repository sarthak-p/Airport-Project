#include <iostream>
#include "graph.h"
#include "readFromFile.cpp"

int main() {
    std::cout << "This is our main file" << std::endl;
    std::vector<airportNode> airportVector = readAirports("data/airports.dat");
    std::cout << "first airportNode: " << airportVector[0].name_ << std::endl;
    std::cout << "second airportNode: " << airportVector[1].name_ << std::endl;
    std::cout << "distance: " << airportVector[0].distance(airportVector[1]) << std::endl;
    return 0;
}
