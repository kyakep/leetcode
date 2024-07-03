/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

//DONE

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int count=1, max_count=0;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i+1]==nums[i]+1){
                count++;
            }
            else if (count>max_count)
                    max_count=count; 
            else
                count=1;
        }
        if (nums.size()==0)
            count = 0;
        return max_count;
    }
};
/*[0,3,7,2,5,8,4,6,0,1]*/
/*int main(){
    Solution s;
    std::vector<int> test;
    test.push_back(0);
    test.push_back(3);
    test.push_back(7);
    test.push_back(2);
    test.push_back(5);
    test.push_back(8);
    test.push_back(4);
    test.push_back(6);
    test.push_back(0);
    test.push_back(1);
    std::cout<<s.longestConsecutive(test)<<"\n";
    for (int i=0; i<6; i++){
        std::cout<<test[i];
    }
}*/