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
    int longestConsecutive(std::vector<int>& nums) {
        int count=1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size()-1; j++){
                if (nums[j]>=nums[j+1]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i+1]==nums[i]+1){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};

/*int main(){
    Solution s;
    std::vector<int> test;
    for (int i=4; i>=0; i--){
        test.push_back(i);
    }
    test.push_back(10);
    s.longestConsecutive(test);
    for (int i = 0; i < test.size(); i++){
        std::cout<<test[i];    
    }
    std::cout<<s.longestConsecutive(test);
    
}*/