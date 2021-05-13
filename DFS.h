#pragma once

#include "flight.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <deque>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include <stack>
#include "adjMatrix.h"

using namespace std;

/**
 * Recursive DFS that traverses all the airports between start and destination airports 
 * */

vector<string> DFS3(int start, int end, adjMatrix myMatrix, vector<bool> visited)
{
    //error checks
    if (myMatrix.indexToName.count(start) == 0) {
        cout << "Error: Starting Location Not Found" << endl;
    }

    if (myMatrix.indexToName.count(end) == 0) {
        cout << "Error: Destination Location Not Found" << endl;
    }

    if (start == end) {
        cout << "You are already at your Destination :-)" << endl;
    }

    //final node to know where to stop
    int final = end;
    string final_name = myMatrix.indexToName[final];

    //vector to keep track of all nodes that connect start and end
    vector<string> track(7698);
    track.push_back(myMatrix.indexToName[start]);

    //setting starting point to true
    visited[start] = true;

    for (int i = 0; i < 7698; i++) {
        if (myMatrix.matrix[start][i] > -1 && (!visited[i])) {
            if (myMatrix.indexToName[i] == final_name) {
                break;
            } else {
                track.push_back(myMatrix.indexToName[i]);
                DFS3(i, end, myMatrix, visited);
            }
        }
    }
    return track;
}
