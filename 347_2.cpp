/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> answer;
        std::map<int, int> mapa;
        std::map<int, std::vector<int> > revermap;
        for (int i = 0; i < nums.size(); i++){
            mapa[nums[i]]++;
        }
        for (const auto& pair : mapa) {
            revermap[pair.second].push_back(pair.first);
        }
        int count=0;
        for (auto pair = revermap.rbegin(); pair != revermap.rend(); ++pair){
            int i=0;
            if (count<k){
                while (count<k && i!=pair->second.size()){
                    answer.push_back(pair->second[i]);
                    i++;
                    count++;
                }
            }
            else{
                break;
            }
        }
        return answer;
    };
};

int main(){
    std::vector<int> test {1, 2, 2, 2, 1, 3, 3, 3};
    int k=2, size=0;
    Solution s;
    std::vector<int> answer = s.topKFrequent(test, k);
    size = answer.size();
    for (int i = 0; i < k; i++) {
        std::cout<<answer[i]<<" ";
    }
}