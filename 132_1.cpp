/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<int> longestConsecutive(std::vector<int>& nums) {
        int count=1;
        if (nums.size()==0){
            count = 0;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i+1]==nums[i]+1){
                count++;
            }

        }
        return nums;
    }
};

int main(){
    Solution s;
    std::vector<int> test { 2,5,6,3,5};
    s.longestConsecutive(test);
    for (int i = 0; i < test.size(); i++){
        std::cout<<test[i];    
    }
    
}