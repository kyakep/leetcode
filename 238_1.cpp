/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

*/

//DONE

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer;
        for (int i = 0; i < nums.size(); i++){
            int product = 1;
            for (int j = 0; j < i; j++)
                product*=nums[j];
            for (int j=i+1; j < nums.size(); j++)
                product*=nums[j];
            if (nums.size()==0){
                return (answer);
            }
            answer.push_back(product);
        }
        return answer;
    }
};

int main(){
    Solution s;
    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    std::vector<int> answer=s.productExceptSelf(test);
    for (int i=0; i<answer.size(); i++){
        std::cout<<answer[i]<<" ";
    }
}