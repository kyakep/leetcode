#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if (s.length() !=t.length()){
            return false;
        }
        std::vector<char> data_s(s.begin(), s.end()), data_t(t.begin(), t.end());
        std::vector<int> check_data_s, check_data_t;
        check_data_s.resize(data_s.size());
        check_data_t.resize(data_t.size());
        int a=1;
        for (int i = 0; i < data_s.size(); i++){
            check_data_s[i]=a;
            check_data_t[i]=a;
            for (int j = 0; j < data_t.size(); j++){
                if (data_s[j]==data_s[i]){
                    check_data_s[j]=check_data_s[i];    
                }
                if (data_t[j]==data_t[i]){
                    check_data_t[j]=check_data_t[i];
                }
            }
            a++;
            
        }
        std::string s_res(check_data_s.begin(), check_data_s.end());
        std::string t_res(check_data_t.begin(), check_data_t.end());
        if (s_res==t_res){
            return true;
        }
        return false;
    }
};

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.
*/

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic 
if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. 
No two characters may map to the same character, 
but a character may map to itself.
*/