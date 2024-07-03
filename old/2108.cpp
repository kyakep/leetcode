/*Given an array of strings words, return the first palindromic string in the array. 
If there is no such string, return an empty string "".*/

#include <vector>
#include <string>

class Solution {
public:
    std::string firstPalindrome(std::vector<std::string>& words) {
        std::string answer = "";

        for (int i = 0; i < words.size(); i++) {
            if (isPalindrome(words[i])){
                answer = words[i];
                return words[i];
            }
        }
        return answer;
    }

    bool isPalindrome(std::string& word){
        for (int i = 0; i < word.length(); i++) {
            int j = word.length() - i - 1;
            if (word[j] == word[i]){
                continue;;
            }
            else{
                return false;
            }
            
        }
        return true;
    }
};