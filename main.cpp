#include <iostream>
#include "graph.h"
#include "readFromFile.cpp"

int main() {
    std::cout << "This is our main file" << std::endl;
    std::vector<airportNode> result = readAirports("data/airports.dat");
    std::cout << "first airportNode: " << result[0].name_ << std::endl;
    return 0;
}
