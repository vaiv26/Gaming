//
//  BFS.cpp
//  LeetCodeProblems
//
//  Created by vaibhav kumar on 10/13/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BFS_Header.h"
#include <deque>
#include <list>

using namespace std;

int main(){
    Graphtrav g(7);
    
    g.addnodes(0, 1);
    g.addnodes(0, 2);
    g.addnodes(1, 3);
    g.addnodes(1, 4);
    g.addnodes(2, 5);
    g.addnodes(2, 6);
    
    g.bfsalgo(0);
    
    return 0;
}
