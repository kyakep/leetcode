/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    set<int> charSet(nums.begin(), nums.end());
    int max = 1;
    int current = 1;
    int prevNum;

    std::set<int>::iterator it = charSet.begin();
    prevNum = *it;

    if (it != charSet.end()) {
      ++it;
    }
    else {
      return 0;
    }

    for (; it != charSet.end(); ++it) {
      if (*it == prevNum + 1) {
        current++;
        if(current > max) {
          max = current;
        }
        prevNum = *it;
        continue;
      }
      else {
        current = 1;
        prevNum = *it;
        continue;
      }
    }

    return max;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {};

  cout<<sol.longestConsecutive(nums);
}