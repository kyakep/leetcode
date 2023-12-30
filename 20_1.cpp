/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, int> chars;
        if (s.length() == 0 || s.length() == 1){
            return true;
        }
        int end_index = s.length() - 1;
        for (int i = 0; i < end_index/2; i++){
            if (s[i] == s[end_index]){
                if (s[i]%2 == 0){
                    chars.erase(s[i]);
                }
                chars[s[i]]++;
                end_index--;
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    std::string input = "()[]{}";
    std::cout << std::boolalpha;   
    std::cout << solution.isValid(input);
}