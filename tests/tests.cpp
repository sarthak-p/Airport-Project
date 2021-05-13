#include "../cs225/catch/catch.hpp"
#include "../graph.h"
#include "../readFromFile.cpp"
#include "../adjMatrix.h"
#include "../centrality.h"

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

TEST_CASE("Succesfully tests centrality @ JFK", "[weight=1'") {
    vector<airportNode> airportVector = readAirports("data/airports.dat");
    vector<route> routeVector = readRoutes("data/routes.dat");
    adjMatrix testMatrix(airportVector, routeVector);
    string source = "JFK";
    string centrality = calcCentrality(testMatrix, source, airportVector.size());
    REQUIRE(centrality != "Looks like you input the wrong size airport code.");
    REQUIRE(centrality != "This airport code couldn't be found.");
    REQUIRE(centrality == "The Normalized Degree Centrality for JFK is 0.020787.");
}

TEST_CASE("Succesfully tests centrality @ faulty input", "[weight=1'") {
    vector<airportNode> airportVector = readAirports("data/airports.dat");
    vector<route> routeVector = readRoutes("data/routes.dat");
    adjMatrix testMatrix(airportVector, routeVector);
    string source = "ORDD";
    string centrality = calcCentrality(testMatrix, source, airportVector.size());
    REQUIRE(centrality != "This airport code couldn't be found.");
    REQUIRE(centrality == "Looks like you input the wrong size airport code.");
}

TEST_CASE("Succesfully tests centrality @ unknown airport", "[weight=1'") {
    vector<airportNode> airportVector = readAirports("data/airports.dat");
    vector<route> routeVector = readRoutes("data/routes.dat");
    adjMatrix testMatrix(airportVector, routeVector);
    string source = "ZZZ";
    string centrality = calcCentrality(testMatrix, source, airportVector.size());
    REQUIRE(centrality != "Looks like you input the wrong size airport code.");
    REQUIRE(centrality == "This airport code couldn't be found.");
}