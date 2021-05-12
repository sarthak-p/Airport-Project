#include <iostream>
#include "graph.h"
#include "readFromFile.cpp"
#include "adjMatrix.h"
#include "dijkstra.h"

using namespace std;

void sebby();
string getInput(const string &question, const bool &allCaps);
void getInput(string &startAirport, string &endAirport);
bool checkIATAFormat(const string &code);
void checkCapitalization(string &text);

int main() {
    //std::cout << "Open main file" << std::endl;
    string startAirportCode, endAirportCode;
    getInput(startAirportCode, endAirportCode);
    std::vector<airportNode> airportVector = readAirports("data/airports.dat");
    std::vector<route> routeVector = readRoutes("data/routes.dat");
    adjMatrix myMatrix(airportVector, routeVector);
   
   /* Start and end airport nodes */
    //std::cout << "first airportNode: " << myMatrix.nameToIndex["\"" + startAirportCode + "\""] << std::endl;
    //std::cout << "second airportNode: " << myMatrix.nameToIndex["\"" + endAirportCode + "\""] << std::endl;
    //std::cout <<"dist in matrix:"<< myMatrix.matrix[3547][3617] << std::endl;
    dijkstra(myMatrix.matrix, myMatrix.nameToIndex["\"" + startAirportCode + "\""], myMatrix.nameToIndex["\"" + endAirportCode + "\""], myMatrix);
    return 0; 
}

/**
void graph_test() {
    vector<Airportnode> a = readAirports();
    vector<route> b = readRoutes();
    Graph graph = Graph(a, b);
    graph.print();
}
**/

// Prompt user to input start and end IATA airport codes
void getInput(string &startAirport, string &endAirport) {
    //std::cout << "Test getInput class" << std::endl;

    bool valid = false;
    while (!valid) {
        startAirport = getInput("Input IATA code of start airport (ALL CAPS): ", true);
        while (!checkIATAFormat(startAirport)) {
          startAirport = getInput("ERROR: Improper format. Try again: ", true);
        }
       
        endAirport = getInput("Input IATA code of end airport (ALL CAPS): ", true);
        while (!checkIATAFormat(endAirport)) {
          endAirport = getInput("ERROR: Improper format. Try again: ", true);
        }

        valid = true;
        if (startAirport == endAirport) {
          cout << "ERROR: Starting and ending airport are the same. Try again." << endl;
          valid = false;
        }
    }
}

// Get input from user
string getInput(const string &question, const bool &allCaps) {
  string line;
  cout << question;
  getline(cin, line);
  if (allCaps) {
    checkCapitalization(line);
  }
  return line;
}

// Returns true if string is in IATA format
bool checkIATAFormat(const string &code) {
  if (code.size() != 3) {
    return false;
  }
  bool checkLetters = true;
  for (size_t i = 0; i < code.size(); ++i) {
    if (!isalpha(code[i])) {
      checkLetters = false;
    }
  }
  return checkLetters;
}

// Helper function to convert string to all caps if needed
void checkCapitalization(string &text) {
  for (size_t i = 0; i < text.size(); ++i) {
    text[i] = toupper(text[i]);
  }
}