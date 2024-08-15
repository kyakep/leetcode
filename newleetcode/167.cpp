#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
      int j = numbers.size() - 1;

      while (numbers[i] + numbers[j] >= target && j > i) {
        if (numbers[i] + numbers[j] == target) {
          answer.push_back(i + 1);
          answer.push_back(j + 1);
          return answer;
        }
        while (numbers[j] == numbers[j-1]) {
          j--;
          break;
        }
        j--;
      }
    }
    return answer;
  }
};

int main() {
  Solution s;

  vector<int> numbers {5,25,75};
  int target = 100;

  vector<int> ans = s.twoSum(numbers, target);

  for (int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
}