#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> mult;
        std::vector<int> reverse_mult;
        std::vector<int> reverse_nums=nums;
        std::reverse(reverse_nums.begin(), reverse_nums.end());
        std::vector<int> result;
        mult.push_back(1);
        reverse_mult.push_back(1);
        for (int i = 1; i<nums.size(); i++){
            mult.push_back(mult[i-1]*nums[i-1]);
            reverse_mult.push_back(reverse_mult[i-1]*reverse_nums[i-1]);
        }
        for (int i = 0; i<nums.size(); i++){
            result.push_back(mult[i]*reverse_mult[reverse_mult.size()-1-i]);
        }
        return result;
    }
};

int main(){
    Solution s;
    std::vector<int> test;
    test.push_back(-1);
    test.push_back(1);
    test.push_back(0);
    test.push_back(-3);
    test.push_back(3);
    std::vector<int> answer=s.productExceptSelf(test);
    for (int i=0; i<answer.size(); i++){
        std::cout<<answer[i]<<" ";
    }
}