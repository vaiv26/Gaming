//
//  main.cpp
//  Hashing
//
//  Created by vaibhav kumar on 8/25/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
void display(vector<T> & v){
    if(v.empty()) return;
    else{
        for(T& i : v )
            cout<<i<<",";
        cout<<endl;
    }
}

int main() {
    string condition = "Y";
    int value,searchValue;
    vector<int> vec;
    while(condition == "Y"||condition == "y")
    {
        cout<<"Insert an element in the vector:";
        cin>>value;
        vec.push_back(value);
        cout<<"Do you want to insert more elements in the vector,Y:yes,N:no:";
        cin>>condition;
    }
    cout<<"Displaying the vector"<<endl;
    display(vec);
    cout<<"Search a number in the vector:";
    cin>>searchValue;
    auto it = find(vec.begin(), vec.end(), searchValue);
    if(it != vec.end()) cout<<"found"<<endl;
    else cout<<"Not found"<<endl;
    return 0;
}
