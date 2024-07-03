/*Given two strings s and t, 
return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

*/

#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> f_word, s_word;
        if (s.length()==t.length()){
            for (int i=0; i<s.length(); i++){
                f_word[s[i]]++;
                s_word[t[i]]++;
            }
            if (f_word==s_word)
                return true;
        }
        return false;
    }
};