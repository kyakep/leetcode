#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        std::unordered_map<char, char> mp;
        int n=0;
        for (int i=0; i<t.length(); i++){
            mp[s[n]]=1;
            if (s[n]==t[i] && i!=t.length()-1)
                n++;
            else if(s[n]==t[i] && i==t.length()-1)
                ;
        }
        if (n==0) 
            n=-1;
        if (n+1==s.length()) 
            return true;
        return false;
    }
};