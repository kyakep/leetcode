// Completed

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  string replaceDigits(string s) {
    string answer = s;
    char alpha[] = "abcdefghijklmnopqrstuvwxyz" ;
	  std::vector<char> alphabet (alpha, alpha+sizeof(alpha)-1);

    if (answer.size() <= 1) {
      return answer;
    }

    for (int i = 1; i < answer.size(); i += 2) {
      auto it = find(alphabet.begin(), alphabet.end(), answer[i - 1]);

      if (it != alphabet.end()) {
        answer[i] = alphabet[(distance(alphabet.begin(), it) + (answer[i] - '0')) % alphabet.size()];
      }
    }

    return answer;
  }
};

int main() {
  string str = "a1b2c3d4e";

  Solution s;
  cout<<s.replaceDigits(str);
}