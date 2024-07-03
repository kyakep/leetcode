/*Given a string s, find the length of the longest 
substring
without repeating characters.*/

#include <string>
#include <iostream>
#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int max_amount=0, current_amount=0;
        std::unordered_map<char, int> amount;
        for (int i=0; i<s.length(); i++){
            amount[s[i]]++;
            current_amount++;
            if (amount[s[i]]>1){
                if (i!=s.length()-1){
                    current_amount--;
                }
                if (current_amount>max_amount)
                    max_amount=current_amount;
                for (int j=0; j<=i; j++) {
                    amount[s[i]]=0;
                }
                current_amount=1;
                amount[s[i]]++;
            }
            else{
                max_amount=current_amount;
            }

        }
        return max_amount;
    }
};

int main(){
    std::string s = "dvdf";
    Solution sol = Solution();
    std::cout<<sol.lengthOfLongestSubstring(s);
}