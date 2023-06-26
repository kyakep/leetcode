/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
*/

#include <vector>
#include <string>
#include <queue>


class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> answer;
        for (int i = 0; i < nums.size(); i++) {
            answer[nums[i]]++;
        }
        std::priority_queue<std::pair<int,int> > pq;
        std::vector<int> answer_vec;
        for (auto it = answer.begin(); it != answer.end(); it++){
            pq.push_back(std::make_pair(it->second, it->first));
            
        }
    }
};