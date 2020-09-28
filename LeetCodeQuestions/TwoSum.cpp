//
//  main.cpp
//  LeetCodeProblems
//
//  Created by vaibhav kumar on 9/23/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.

//Question: Two Sum Problems.
//1. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//2. You may assume that each input would have exactly one solution, and you may not use the same element twice.
//3. You can return the answer in any order.
//
//Example 1:
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Output: Because nums[0] + nums[1] == 9, we return [0, 1].
//
//Example 2:
//Input: nums = [3,2,4], target = 6
//Output: [1,2]
//
//Example 3:
//Input: nums = [3,3], target = 6
//Output: [0,1]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=1;
        vector<int> z = {-1};
        auto k = nums.size()-1;
        auto it = nums.begin();
        for(int m = 0; m < k; m++)
        {
            for(auto second = next(it);second != nums.end();second++)
            {
            int value = *it + *second;
            if(target ==value)
            {
                vector<int> v = {i,j};
                return v;
            }
            j=j+1;
            }
            i=i+1;
            j=i+1;
            it++;
        }
        return z;
        }
};


int main() {
    Solution s;
    vector<int> nums = {3,2,3};
    auto vec = s.twoSum(nums, 6);
    for(auto i:vec)
    {
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}
