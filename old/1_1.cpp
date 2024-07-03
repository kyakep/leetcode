/*Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.*/

#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> answer;
        for (int i=0; i<nums.size()-1; i++)
        {
            for (int j=i+1; j<nums.size(); j++){
                if (nums[i]+nums[j]==target){
                    answer.push_back(i);
                    answer.push_back(j);
                }
            }
        }
        return answer;
    }
};