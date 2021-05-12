#include <iostream>
#include "graph.h"
#include "flight.h"
#include "readFromFile.cpp"
#include "adjMatrix.h"
#include "dijkstra.h"
#include "centrality.h"

using namespace std;

string getInput(const string &question, const bool &allCaps);
void getInput(string &startAirport, string &endAirport);
bool checkIATAFormat(const string &code);
void checkCapitalization(string &text);
void printDFS();

int main() {
    //std::cout << "Open main file" << std::endl;
    int option;
    string startAirportCode, endAirportCode;
    getInput(startAirportCode, endAirportCode);
    std::vector<airportNode> airportVector = readAirports("data/airports.dat");
    // Check if input is a valid IATA code from the data
    int in1 = 0;
    int in2 = 0;
    string startAirportCode, endAirportCode;
    while((!in1 || !in2)) {
      getInput(startAirportCode, endAirportCode);
      in1 = 0;
      in2 = 0;
      for (int i = 0; i < airportVector.size() && (!in1 || !in2); i++) {
        auto apn = airportVector[i];
        if (apn.code_ == "\""+startAirportCode+"\"") {
          in1 = 1;
        }
        if (apn.code_ == "\""+endAirportCode+"\"") {
          in2 = 1;
        }
      }
      if ((!in1 || !in2)) {
        cout << "One or more invalid IATA codes. Try again." << endl;
      }
    }
    std::vector<route> routeVector = readRoutes("data/routes.dat");
    adjMatrix myMatrix(airportVector, routeVector);

    while (true) {
        cout << "Which option of the trip planner would you like to use? Please input a number." << endl;
        cout << "0. Unique trip planner" << endl;
        cout << "1. Shortest path (Dijkstra's)" << endl;
        cout << "2. Check connectedness of an airport" << endl;
        cout << "3. End program" << endl;
        cin >> option;

        // Ensure proper safety of input 
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Looks like you didn't type the correct input" << endl;
            cin >> option;
        }

        // Given user input, perform the desired method.
        if (option == 0) {
            vector<string> routesToUse;
            /*
            routesToUse = flightGraph.DFS2(source, destination, routeVector);
            cout << "Flights connect the following airports for a fun trip: " << endl;
            for (int i = 0; i < routesToUse.size(); i++) {
                cout << routesToUse[i] << endl;
            } */
            cout << "--------------------" << endl;
            cout << "in progress" << endl;
            cout << "--------------------" << endl << endl;
        } else if (option == 1) {
            cout << "--------------------" << endl;
            dijkstra(myMatrix.matrix, myMatrix.nameToIndex["\"" + startAirportCode + "\""], myMatrix.nameToIndex["\"" + endAirportCode + "\""], myMatrix);
            cout << endl << "--------------------" << endl << endl;
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
            centrality = calcCentrality(myMatrix, inputAirport);
            //centrality = "testing";
            cout << "--------------------" << endl;
            cout << centrality << endl;
            cout << "--------------------" << endl << endl;
        } else {
            cout << "--------------------" << endl;
            cout << "Exiting the program." << endl;
            cout << "--------------------" << endl << endl;
            return 0;
        }
    }    
   
   /* Start and end airport nodes */
    //std::cout << "first airportNode: " << myMatrix.nameToIndex["\"" + startAirportCode + "\""] << std::endl;
    //std::cout << "second airportNode: " << myMatrix.nameToIndex["\"" + endAirportCode + "\""] << std::endl;
    //std::cout <<"dist in matrix:"<< myMatrix.matrix[3547][3617] << std::endl;
    dijkstra(myMatrix.matrix, myMatrix.nameToIndex["\"" + startAirportCode + "\""], myMatrix.nameToIndex["\"" + endAirportCode + "\""], myMatrix);
    return 0; 
}


/**
 * Prompt user to input start and end IATA airport codes
 * */
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

/**
 * Get string input from user 
 * */
string getInput(const string &question, const bool &allCaps) {
  string line;
  cout << question;
  getline(cin, line);
  if (allCaps) {
    checkCapitalization(line);
  }
  return line;
}

/**
 * Checks if the string is in IATA format 
 * */
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

/**
 * Helper function to capitalize input string 
 * */
void checkCapitalization(string &text) {
  for (size_t i = 0; i < text.size(); ++i) {
    text[i] = toupper(text[i]);
  }
}

//void printDFS(vector )

