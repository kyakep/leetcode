#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;

void checkValudacity (std::pair<int, int> current, std::pair<int, int>& max) {
  if (current.second > max.second) { 
    max.second = current.second;
    max.first = current.first;
  }
}

class Solution {
public:
  int maximumPopulation(vector<vector<int>>& logs) {
    std::pair<int, int> max = {logs[0][0], 0};
    std::pair<int, int> currentMax = {logs[0][0], 1};

    for (int i = 1; i < logs.size(); i++) {
      if (logs[i][0] > logs[i-1][1]) {
        currentMax.second--;
        currentMax.first = logs[i][0];
        checkValudacity(currentMax, max);
      }
      if (logs[i][1] > currentMax.first) {
        currentMax.second++;
        currentMax.first = logs[i][0];
        checkValudacity(currentMax, max);
      }
    }
    return max.first;
  }
};

int main() {
  vector<vector<int>> logs {{1950,1961},{1960,1971},{1970,1981}};

  Solution s;
  cout<<s.maximumPopulation(logs);


}