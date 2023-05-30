/*
Given two strings s and t, return true if s is a subsequence of t, 
or false otherwise.

A subsequence of a string is a new string that is formed from the original string 
by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

#include <string>
#include <vector>
#include <iostream>

//создать вектор, который будет заполняться только повторками букв из второго стринга (долго)

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        std::string s_in=s, t_in=t;
        std::vector<char> sym;
        int n=0;
        for (int i = 0; i < s_in.length(); i++){
            for (int j = 0; j<t_in.length(); j++){
                if (t_in[j]==s_in[i]){
                    sym.push_back(t_in[j]);
                    n++;
                }
            }
            if (s_in[i]!=sym[i])
                return false;
            else if (i+1 != sym.size())
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    std::cout<<s.isSubsequence("axc","ahbgdc");
}