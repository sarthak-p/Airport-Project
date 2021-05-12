#include "centrality.h"
#include "adjMatrix.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

string calcCentrality(Flight & input, string airportCode) {
    //vector<airportNode> temp;
    int nodeSize = input.mp.size();
    int edgeCounter = 0;
    // Change once adj. matrix var is added into Flight class
    map<string, int>::iterator it = input.mp.find(airportCode);

    // Check input for errors before centrality is calculated
    if (airportCode.size() != 3) {
        return "Looks like you input the wrong size airport code.";
        // Update else if once adj. matrix var added
    } else if (it == input.mp.end()) {
        // Check if airportCode can be found in input Flight object
        return "This airport code couldn't be found.";
    }

    int airportIdx = it->second;
    for (int i = 0; i < nodeSize; i++) {
        if (matrix[i][airportIdx] == 1) {
            edgeCounter++;
        }
    }

    double normalizedCentrality = edgeCounter / (nodeSize - 1);
    return "The Normalized Degree Centrality for " + airportCode + " is " + to_string(normalizedCentrality) + ".";
}

int main() {
    int option;
    vector<airportNode> airportVector = readAirports("data/airports.dat");
    vector<route> routeVector = readRoutes("data/routes.dat");
    Flight flightGraph(airportVector, routeVector);

    while (true) {
        cout << "Which option of the trip planner would you like to use? Please input a number." << endl;
        cout << "0. Unique trip planner" << endl;
        cout << "1. Shortest path (Dijkstra's)" << endl;
        cout << "2. Check connectedness of an airport" << endl;
        cout << "3. End program" << endl;
        cin >> option;

        // Ensure proper safety of input 
        while (cin.fail() || option < 0 || option > 3) {
            cin.clear();
            cin.ignore();
            cout << "Looks like you type the correct input" << endl;
            cin >> option;
        }

        // Given user input, perform the desired method.
        if (option == 0) {
            string source, destination;
            vector<string> routesToUse;

            cout << "Please enter the capitalized 3-letter airport code for the source airport." << endl;
            cin >> source;
            while (cin.fail() || source.length() != 3) {
                cin.clear();
                cin.ignore();
                cout << "Try inputting the airport again." << endl;
                cin >> source;
            }

            cout << "Please enter the capitalized 3-letter airport code for the destination airport." << endl;
            cin >> destination;
            while (cin.fail() || destination.length() != 3) {
                cin.clear();
                cin.ignore();
                cout << "Try inputting the airport again." << endl;
                cin >> destination;
            }
            
            routesToUse = flightGraph.DFS2(source, destination, routeVector);
            cout << "Flights connect the following airports for a fun trip: " << endl;
            for (int i = 0; i < routesToUse.size(); i++) {
                cout << routesToUse[i] << endl;
            }
        } else if (option == 1) {
            string source, destination;
            cout << "Please enter the capitalized 3-letter airport code for the source airport." << endl;
            cin >> source;
            while (cin.fail() || source.length() != 3) {
                cin.clear();
                cin.ignore();
                cout << "Try inputting the airport again." << endl;
                cin >> source;
            }

            cout << "Please enter the capitalized 3-letter airport code for the destination airport." << endl;
            cin >> destination;
            while (cin.fail() || destination.length() != 3) {
                cin.clear();
                cin.ignore();
                cout << "Try inputting the airport again." << endl;
                cin >> destination;
            }
            dijkstra(myMatrix.matrix, myMatrix.nameToIndex["\"" + startAirportCode + "\""], myMatrix.nameToIndex["\"" + endAirportCode + "\""], myMatrix);
        } else if (option == 2) {
            string inputAirport, centrality;
            cout << "Enter the capitalized 3-letter airport code you would like to check for degree centrality." << endl;
            cin >> inputAirport;

            while (cin.fail() || inputAirport.length() != 3) {
                cin.clear();
                cin.ignore();
                cout << "Try inputting the airport again." << endl;
                cin >> inputAirport;
            }
            centrality = calcCentrality(flightGraph, inputAirport);
            cout << centrality << endl;
        } else {
            cout << "--------------------" << endl;
            cout << "Exiting the program." << endl;
            cout << "--------------------" << endl;
            return 0;
        }
    }    
    return 0;
}

