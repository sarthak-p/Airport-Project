#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <stack>
#include "adjMatrix.h"

using namespace std;

/**
 * Iterative DFS that traverses the whole graph from start 
 * */
vector<string> DFS(int start, int end, vector<bool> visited, adjMatrix myMatrix, int size) {
    
    //stack to hold all of the nodes
    stack<int> reference;

    //vector to keep track of the visited pomts 
    vector<string> track(size);
    track.push_back(myMatrix.indexToName[start]); //push start into track 

    //add start as a visited point 
    visited[start] = true;

    //add our start point to the stack 
    reference.push(start);

    //while stack is not empty 
    while (!reference.empty()) {
        int top = reference.top();  //save the top point and pop it 
        reference.pop();

        //check for all adjacent edges of every point from the adjacency matrix and add it to the stack 
        for (int i = 0; i < size; i++) {
            if (myMatrix.matrix[start][i] != -1 && myMatrix.matrix[start][i] != 0 && (!visited[i])) {
                track.push_back(myMatrix.indexToName[i]);
                visited[i] = true;
                reference.push(i);
            }
        }
    }
    //return the vector of points 
    return track;
}

/**
 * Modified version of DFS where we traverse only through given start and end points 
 * */
vector<string> DFS2(int start, int end, vector<bool> visited, adjMatrix myMatrix, int size) {
    //stack to hold all of the nodes 
    stack<int> reference;

    //vector to track all the points 
    vector<string> track(size);
    track.push_back(myMatrix.indexToName[start]); //push start into the vector 

    //mark the start point as visited 
    visited[start] = true;

    //push the start point into the stack 
    reference.push(start);

    //while stack is not empty 
    while (!reference.empty()) {
        int top = reference.top(); //take the top point and pop it 
        reference.pop();

        //if our start point is the same as the end point, then we are done 
        //NOTE: the function does not add the destination airport in the list since we break before that.
        //      However, we still add the airport before the destination airport
        if (start == end) {
            track.push_back(myMatrix.indexToName[end]);
            break;
        }

        //find the adjacent nodes of all nodes from the adjacency matrix and perform DFS 
        for (int i = 0; i < size; i++) {
            if (myMatrix.matrix[start][i] != -1 && myMatrix.matrix[start][i] != 0 && (!visited[i])) {
                track.push_back(myMatrix.indexToName[i]);
                visited[i] = true; 
                reference.push(i);
            }
        }
    }
    //return all the points between the two given airports 
    return track;
}
