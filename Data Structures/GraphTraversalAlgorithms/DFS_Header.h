//
//  DFS_Header.h
//  LeetCodeProblems
//
//  Created by vaibhav kumar on 10/13/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//

#ifndef DFS_Header_h
#define DFS_Header_h

#include <iostream>
#include "DFS_Header.h"
#include <stack>
#include <vector>
using namespace std;

class Graphtrav{
    int numVertices;
    vector<int>* adjacents;
    bool* visited;
public:
    Graphtrav(int vertices);
    void addNodes(int src, int dest);
    void DFSalgo(int startnode);
};

Graphtrav::Graphtrav(int vertices){
    numVertices = vertices;
    adjacents = new vector<int>[vertices];
    visited = new bool[vertices];
}

void Graphtrav::addNodes(int src,int dest){
    adjacents[src].push_back(dest);
}

void Graphtrav::DFSalgo(int startnode){
    for(int i = 0; i < numVertices; i++){
        visited[i] = false;
        reverse(adjacents[i].begin(),adjacents[i].end());
    }
    
    stack<int> stk;
    
    visited[startnode] = true;
    stk.push(startnode);
    
    while(!stk.empty()){
        int top = stk.top();
        cout<<top<<",";
        stk.pop();
        if(!visited[top])
            visited[top] = true;
        
        for(auto v: adjacents[top]){
            if(!visited[v]){
                stk.push(v);
            }
        }
    }
    cout<<endl;
}

#endif /* DFS_Header_h */
