// Completed

/*
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    std::vector<int> answer(temperatures.size(), 0);
    std::vector<pair<int, int>> tempStack;

    if (temperatures.size() == 0 || temperatures.size() == 1) {
      return answer;
    }

    tempStack.push_back(std::make_pair(temperatures[0], 0));

    for (int i = 1; i < temperatures.size(); i++) {
      while (tempStack.size() > 0 && temperatures[i] > tempStack[tempStack.size() - 1].first) {
        answer[tempStack[tempStack.size() - 1].second] = i - tempStack[tempStack.size() - 1].second;
        tempStack.pop_back();
      }
      tempStack.push_back(make_pair(temperatures[i], i));
    }

    return answer;
  }
};

int main() {
  Solution s;

  vector<int> tempArray {73,74,75,71,69,72,76,73};

  vector<int> ans = s.dailyTemperatures(tempArray);

  for (auto i : ans) {
    cout<<i<<" ";
  }
}