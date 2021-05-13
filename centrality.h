#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "graph.h"
#include "flight.h"
#include "adjMatrix.h"

using namespace std;

/**
 * @param Input flight (graph) object
 * @param node 3-letter IATA code for the airport in question
 * @return a string detailing the normalized degree centrality of a given node 
 */ 
string calcCentrality(adjMatrix & inputMatrix, string & airportCode, double airportSize);