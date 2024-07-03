/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.*/

#include <vector>
#include <iostream>
#include <set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::set<int> ordered;
        int num = 0;
        int current = 1, max = 0;
        for (int i = 0; i < nums.size(); i++) {
            ordered.insert(nums[i]);
        }
        if (ordered.size() == 1){
            return 1;
        }
        else if (ordered.size() == 0){
            return 0;
        }
        for (auto it = ordered.begin(); it != std::prev(ordered.end(),1); it++) {
            if (*std::next(it, 1) == *it+1){
                current++;
                if (current >= max){
                    max = current;
                }
            }
            else {
                if (current >= max){
                    max = current;
                }
                current = 1;
            }
        }
        return max;
    }
};

int main(){
    Solution s; // 0,1,2,3,4,5,6,7,8
    std::vector<int> test{0,0};
    std::cout<<s.longestConsecutive(test);
}
