#include "../cs225/catch/catch.hpp"
#include "../graph.h"
#include "../readFromFile.cpp"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("Succesfully parses airports", "[weight=1]") {
    vector<airportNode> result = readAirports("data/airports.dat");
    airportNode firstAirport = result[0];
    airportNode secondAirport = result[1];
    double distance = firstAirport.dist(secondAirport);
    REQUIRE(firstAirport.code_ == "\"GKA\"");
    REQUIRE(distance > 100);
    REQUIRE(distance < 110);
}

TEST_CASE("Succesfully parses routes", "[weight=1]") {
    vector<route> result = readRoutes("data/routes.dat");
    route firstRoute = result[0];
    REQUIRE(firstRoute.source == "AER");
    REQUIRE(firstRoute.destination == "KZN");
}