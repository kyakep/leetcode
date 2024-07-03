#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  std::string removeNonAlphanumeric(const std::string& s) {
    std::string result;
    for (char c : s) {
      if (std::isalnum(c)) {
        result += c;
      }
    }
    return result;
  }
  
  bool isPalindrome(string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    s = removeNonAlphanumeric(s);
    if (s.size() == 1 || s.size() == 0) {
      return true;
    }

    for (int i = 0; i < s.size() / 2; i++) {
      if (s[i] != s[s.size() - i - 1]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string s = "A man, a plan, a canal: Panama";
  cout<<sol.isPalindrome(s);
}