// Completed

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
  Every close bracket has a corresponding open bracket of the same type.

*/

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    vector<char> currentBrasketsVector;
    int equ = 0;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
        currentBrasketsVector.push_back(s[i]);
        equ++;
        continue;
      }
      else if (currentBrasketsVector.size() == 0) {
        equ--;
        continue;
      }
      else if (s[i] == ']' && currentBrasketsVector[currentBrasketsVector.size() - 1]  == '[') {
        equ--;
        currentBrasketsVector.pop_back();
        continue;
      }
      else if (s[i] == '}' && currentBrasketsVector[currentBrasketsVector.size() - 1] == '{') {
        equ--;
        currentBrasketsVector.pop_back();
        continue;
      }
      else if (s[i] == ')' && currentBrasketsVector[currentBrasketsVector.size() - 1] == '(') {
        equ--;
        currentBrasketsVector.pop_back();
        continue;
      }
      else {
        return false;
      }
    }
    if (currentBrasketsVector.size() == 0 && equ == 0) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution sol;

  string input = "()";
}