#include <vector>
#include <string>

/*Given an integer array nums, 
return true if any value appears at least twice in the array, 
and return false if every element is distinct.*/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            if (map[nums[i]]>1)
                return true;
        }
        return false;
    }
};