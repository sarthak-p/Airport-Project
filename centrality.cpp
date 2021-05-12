#include "centrality.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string calcCentrality(Flight & input, string airportCode) {
    vector<airportNode> temp;

    if (airportCode.size() != 3) {
        return "Looks like you input the wrong size airport code.";
    } else if () {
        // Check if airportCode can be found in input Flight object
        return "This airport code couldn't be found.";
    }

    return "result";
}

