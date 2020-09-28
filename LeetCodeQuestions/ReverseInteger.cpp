//
//  ReverseInteger.cpp
//  LeetCodeProblems
//
//  Created by vaibhav kumar on 9/23/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//
// Question: Reverse Integers
// Given a 32-bit signed integer, reverse digits of an integer.
//
//Example1:
//Input: 123
//Output: 321
//
//Example2:
//Input: -123
//Output: -321
//
//Example3:
//Input: 120
//Output: 21

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int d=0,rev,c,num=x;
        if(x<0) x = x * -1;
        while(x > 0)
        {
            c = x%10;
            rev = (d * 10) + c;
            d = rev;
            x = x/10;
        }
        if(num < 0) return (rev * -1);
        return rev;
    }
};

int main()
{
    int num;
    Solution s;
    cout<<"Number to be reversed:";
    cin>>num;
    cout<<s.reverse(num)<<endl;
    return 0;
}
