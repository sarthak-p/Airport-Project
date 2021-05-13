#include "centrality.h"
#include "adjMatrix.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

string calcCentrality(adjMatrix & inputMatrix, string & airportCode, double airportSize) {
    //int nodeSize = inputMatrix.nameToIndex.size();
    size_t edgeCounter = 0;
    string code = "\"" + airportCode + "\"";
    map<string, int>::iterator it = inputMatrix.nameToIndex.find(code);

    // Check input for errors before centrality is calculated
    if (airportCode.size() != 3) {
        return "Looks like you input the wrong size airport code.";
    } else if (it == inputMatrix.nameToIndex.end()) {
        return "This airport code couldn't be found.";
    }

    int airportIdx = it->second;
    for (size_t i = 0; i < airportSize; i++) {
        if (inputMatrix.matrix[i][airportIdx] != -1 && inputMatrix.matrix[i][airportIdx] != 0) {
            edgeCounter++;
        }
    }

    double normalizedCentrality = edgeCounter / (airportSize - 1);
    return "The Normalized Degree Centrality for " + airportCode + " is " + to_string(normalizedCentrality) + ".";
}