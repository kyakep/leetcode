/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic 
if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. 
No two characters may map to the same character, 
but a character may map to itself.
*/

#include <vector>
#include <string>

class Solution{
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char>  mp, mp2;
        for (int i=0; i<s.length(); ++i) {
            if (mp[s[i]] && mp[s[i]]!=t[i])
                return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i])
                return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};