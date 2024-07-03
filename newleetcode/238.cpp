// Completed

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product 
of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include <algorithm> 
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    map<int, pair<int, int>> charToNumber;
    vector<int> ans(nums.size());
    int product = 1;
    bool manyZeros = 0;
    bool anyZeros = 0;

    for (int i = 0; i < nums.size(); i++) {
      charToNumber[nums[i]].first = i;
      charToNumber[nums[i]].second++;
    }

    for (auto i : charToNumber) {
      if (i.first != 0) {
        product *= pow(i.first, i.second.second);
      }
    }

    if (charToNumber[0].second > 1) {
      manyZeros = 1;
    }
    else if (charToNumber[0].second == 1) {
      anyZeros = 1;
    }
    else {
      anyZeros = 0;
    }

    if (manyZeros) {
      return ans;
    }
    else if (anyZeros) {
      ans[charToNumber[0].first] = product;
      return ans;
    }
    
    for (int i = 0; i < ans.size(); i++) {
      ans[i] = product / nums[i];
    }
    return ans;
  }
};

int main() {
  Solution sol;

  vector<int> nums{-1,1,0,-3,3};
  vector<int> ans = sol.productExceptSelf(nums);

  for (auto i : ans) {
    cout<<i<<" ";
  }
}