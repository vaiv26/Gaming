//
//  BinarySearch.cpp
//  Search
//
//  Created by vaibhav kumar on 9/22/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
using namespace std;

template <typename T,size_t n>
void display(array<T,n> & arr)
{
    for(T& i : arr)
        cout<<i<<",";
    cout<<endl;
}

int main()
{
    int searchValue,middle,l=0,r = 9,f=-1;
    array<int, 10> arr = {1,5,2,17,27,6,8,9,4,3};
    cout<<"Displaying the array"<<endl;
    display(arr);
    
    sort(arr.begin(), arr.end());
    
    cout<<"Enter number to search:";
    cin>>searchValue;
    
    cout<<"Searching with binary search STL function"<<endl;
    if(binary_search(arr.begin(), arr.end(), searchValue))cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    
    cout<<"Searching with binary serach function"<<endl;
    while(l <= r)
    {
        middle = l + (r-l)/2;
        if(arr[middle] == searchValue) f=0;
        if(arr[middle] < searchValue) l = middle + 1;
        else r = middle - 1;
    }
    if(f == -1) cout<<"Not Found"<<endl;
    else cout<<"Found"<<endl;
    return 0;
}

