#include <vector>
#include <iostream>
#include <map>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int iAns = 0, jAns, kAns;
        std::map<int, int> orderedList;
        for (int i = 0; i < nums.size(); i++) {
            orderedList[nums[i]] = i;
        }

    }

    bool checkValid(std::map<int, int>& list) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i]
        }
    }
};