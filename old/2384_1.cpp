/*You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. 
It should not contain leading zeroes.*/
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string largestPalindromic(std::string num) {
        std::unordered_map<int, int> nums;
        for (int i = 0; i < num.length(); i++) {
            if (num[i] != '0') {
                std::stod(num[i], 1);
            }
        }
    }
};