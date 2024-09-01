// Completed

#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

class Solution {
public:
  static bool sortPairs(const pair<int, int>& left, const pair<int, int>& right) {
    return left.first < right.first;
  }

  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<pair<int, int>> numsToIndex;
    set<vector<int>> uniqueCombos;

    for (int i = 0; i < nums.size(); i++) {
      numsToIndex.push_back(make_pair(nums[i], i));
    }

    std::sort(numsToIndex.begin(), numsToIndex.end(), sortPairs);

    for (int i = 0; i < numsToIndex.size() - 2; i++) {
      int j = i + 1;
      int k = numsToIndex.size() - 1;

      auto iValue = numsToIndex[i];

      while (j < k) {
        auto jValue = numsToIndex[j];
        auto kValue = numsToIndex[k];

        // cout<<iValue<<" "<<jValue<<" "<<kValue<<" "<<endl;

        if (iValue.first + jValue.first + kValue.first == 0) {
          vector<int> temp {iValue.first, jValue.first, kValue.first};
          uniqueCombos.insert(temp);
          j++;
          k--;
        }
        else if (iValue.first + jValue.first + kValue.first < 0) {
          j++;
        }
        else if (iValue.first + jValue.first + kValue.first > 0) {
          k--;
        }
      }
    }

    vector<vector<int>> answer (uniqueCombos.begin(), uniqueCombos.end());
    
    return answer;
  }
};

int main() {
  Solution s;
  vector<int> nums {-2,0,1,1,2};
  vector<vector<int>> result = s.threeSum(nums);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
}