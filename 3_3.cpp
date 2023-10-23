/*Given a string s, find the length of the longest 
substring
without repeating characters.*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<char> result;
        int current = 0, max = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < result.size(); j++) {
                if (s[i]==result[j]){
                    result.erase(result.begin(), result.begin() + j+1);
                    if (current > max) { 
                        max = current;
                    }
                }
            }
            result.push_back(s[i]);
            current = result.size();
            if (current > max) {
                max = current;
            }
        }
        return max;
    }
};