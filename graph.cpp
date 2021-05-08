#include "graph.h"
#include <iostream>

using namespace std; 
/**

Graph::Graph(vector<airportNode> first, vector<route> second) {
    makeGraph(vector<airportNode> first, vector<route> second);
}

void Graph::makeGraph(vector<airportNode> airports, vector<route> routes) {
    //iterate through the routes vector and get the source and destination of each object 
    for (auto it = routes.begin(); it != routes.end; ++it) {
        string source = (*it).source;
        string destination = (*it).destination;

    //find the corresponding airportNode of the source and destination strings respectively
        auto iter1 = find_if(airports.begin(), airports.end(), [&source](const airportNode & obj) { return obj.getName() == source; })
        if (iter1 != airports.end()) { airportNode source_ = (*iter1); }

        auto iter2 = find_if(airports.begin(), airports.end(), [&destination](const airportNode & obj2) { return obj2.getName() == destination; })
        if (iter2 != airports.end()) { airportNode destination_ = (*iter2); }

    //if the source
        if (destination == destination_.code_ && source == source_.code_) {
            double dist = source_.distance(destination_);
            adjL[source_].push_back(make_pair(destination_, dist));
        } else {
            cout << "Either the Source or Destination airports do not exist";
        }
    }
}

void Graph::print() {
    for (auto pair : adjL) {
        string initial = pair.first; 
        list<pair<string, double> > destinations = pair.second; 

        cout << initial << "->";
        for (auto d : destinations) {
            string one = destinations.first; 
            double weight = destionations.second; 
            cout << one << " " << weight << ",";
        }
        cout << endl; 
    }
}

unordered_map<airportNode, list<pair<airportNode, double>>> Graph::getGraph() {
    return adjL;
}**/