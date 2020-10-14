//
//  BFS_Header.h
//  LeetCodeProblems
//
//  Created by vaibhav kumar on 10/13/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//
#ifndef BFS_Header_h
#define BFS_Header_h

#include <list>
#include <deque>
#include <iostream>
using namespace std;

class Graphtrav{
    int numVertices;
    list<int>* adjacents;
    bool* visited;
public:
    Graphtrav(int vertices);
    void addnodes(int src, int nodes);
    void bfsalgo(int startnode);
};

Graphtrav::Graphtrav(int vertices){
    numVertices = vertices;
    adjacents = new list<int>[vertices];
    visited = new bool[numVertices];
}

void Graphtrav::addnodes(int src, int nodes){
    adjacents[src].push_back(nodes);
    adjacents[nodes].push_back(src);
}

void Graphtrav::bfsalgo(int startnode){
    for(int i = 0; i < numVertices; i++){
        visited[i] = false;
    }
    
    deque<int> d;
    
    visited[startnode] = true;
    d.push_back(startnode);
    
    while(!d.empty()){
        int currVert = d.front();
        cout<<currVert<<",";
        d.pop_front();
        
        for(auto v: adjacents[currVert]){
            int i = v;
            if(!visited[i]){
                visited[i] = true;
                d.push_back(i);
            }
        }
    }
    cout<<endl;
}

#endif /* BFS_Header_h */
