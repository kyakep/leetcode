// Completed

/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
*/

#include <algorithm> 
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> charToNum;
    for (auto i : nums) {
      charToNum[i]++;
    }

    vector<pair<int, int>> vecCharToNum;

    for (auto& it : charToNum) {
      vecCharToNum.push_back(it);
    }

    sort(vecCharToNum.begin(), vecCharToNum.end(), [](auto& a, auto& b) { 
      return a.second > b.second; 
    }); 
    
    vector<int> answer;
    for (int it = 0; it < k; it++) {
      answer.push_back(vecCharToNum[it].first);
    }
    return answer;
  }
};

int main() {
  Solution sol;

  vector<int> nums{1,1,1,2,2,3,4,4,4,4};

  vector<int> ans = sol.topKFrequent(nums, 2);

  for (auto i : ans) {
    cout<<i<<" ";
  }
}