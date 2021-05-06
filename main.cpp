#include <iostream>
#include "graph.h"
#include "readFromFile.cpp"

int main() {
    std::cout << "This is our main file" << std::endl;
    std::vector<airportNode> airportVector = readAirports("data/airports.dat");
    std::cout << "first airportNode: " << airportVector[0].name_ << std::endl;
    std::cout << "second airportNode: " << airportVector[1].name_ << std::endl;
    std::cout << "distance: " << airportVector[0].distance(airportVector[1]) << std::endl;

    std::vector<route> routeVector = readRoutes("data/routes.dat");
    std::cout << "Route #1 source: " << routeVector[0].source << std::endl;
    std::cout << "Route #2 destination: " << routeVector[0].destination << std::endl;

    return 0;
}
