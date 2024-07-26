// Completed

#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    std::size_t start = 0;

    if (str[0] == '-' || str[0] == '+') {
      if (str.size() == 1) return false;
      start = 1;
    }

    for (std::size_t i = start; i < str.size(); ++i) {
      if (!std::isdigit(str[i])) {
        return false;
      }
    }

    return true;
  }

  int evalRPN(vector<string>& tokens) {
    vector<int> nums;

    for (auto i : tokens) {
      if (isNumber(i)) {
        nums.push_back(stoi(i));
      }
      else if (nums.size() >= 2){
        int firstNum = nums[nums.size() - 1];
        nums.pop_back();
        int secondNum = nums[nums.size() - 1];;
        nums.pop_back();

        // cout<<firstNum<<endl;
        // cout<<secondNum<<endl;

        if (i == "+") {
          nums.push_back(secondNum + firstNum);
          // cout<<secondNum + firstNum<<endl;
        }
        if (i == "-") {
          nums.push_back(secondNum - firstNum);
          // cout<<secondNum - firstNum<<endl;
        } 
        if (i == "*") {
          nums.push_back(secondNum * firstNum);
          // cout<<secondNum * firstNum<<endl;
        }
        if (i == "/" && firstNum != 0) {
          nums.push_back(secondNum / firstNum);
          // cout<<secondNum / firstNum<<endl;
        }
      }
    }

    return nums[0];
  }
};

int main() {
  Solution s;
  vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  int ans = s.evalRPN(tokens);
  cout<<ans;
}