/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
*/

#include <vector>
#include <string>


class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> answer;
        for (int i = 0; i < nums.size(); i++) {
            answer[nums[i]]++;
        }
        for (int i = 0; i < answer.size()-1; i++) {
            for (int j = 0; j < answer.size()-1; j++) {
                if (answer[j]<answer[j+1]){
                    int temp=answer[j];
                    answer[j] = answer[j+1];
                    answer[j+1] = temp;
                }
            }
        }
        std::vector<int> answer_vec;
        for (int i=0; i<k; i++)
        {
            answer_vec.push_back(answer[i]);
        }
        return answer_vec;
    }
};