//
//  DFS.cpp
//  LeetCodeProblems
//
//  Created by vaibhav kumar on 10/13/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "DFS_Header.h"
#include <stack>
#include <vector>
#include <list>
using namespace std;

int main(){
    Graphtrav g(7);
    
    g.addNodes(0, 1);
    g.addNodes(0, 2);
    g.addNodes(1, 3);
    g.addNodes(1, 4);
    g.addNodes(2, 5);
    g.addNodes(2, 6);
    
    g.DFSalgo(0);
    
    return 0;
}
