/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
*/

#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++){
            um[nums[i]]++;
        }

    }
};

int main(){
    Solution s;
    int test = [2,3,5,2,3];
    s.topKFrequent(
}