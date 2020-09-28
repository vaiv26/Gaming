//
//  Palindrome Number.cpp
//  LeetCodeProblems
//
//  Created by vaibhav kumar on 9/23/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//
//Question : Palindrome Number
//Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
//Exa mple 1:
//Input: 121
//Output: true
//
//Example 2:
//Input: -121
//Output: false
//Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
//Example 3:
//Input: 10
//Output: false
//Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int d=0,rev,c,num=x;
        if((x/10)<0) return false;
        else if(x==0) return true;
        else{
            while(x > 0)
            {
                c = x%10;
                rev = (d * 10) + c;
                d = rev;
                x = x/10;
            }
            if(num == rev) return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    int num;
    cout<<"Enter a number to check for palindrome:";
    cin>>num;
    cout<<(s.isPalindrome(num)==1? "true":"false")<<endl;
}
