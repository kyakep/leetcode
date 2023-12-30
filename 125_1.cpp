/*A phrase is a palindrome if, 
after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.*/

#include <string>
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            while (!std::isalpha(s[i])){
                s.erase(i, 1);
                i++;
            }
            while (!std::isalpha(s[j])){
                s.erase(j, 1);
                j--;
            }
            if (s.length() == 0){
                return true;
            }
            if (std::tolower(s[i])!= std::tolower(s[j])) {
                return false;
            }
            else {
                i++;
                j--;
                continue;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    std::string test = "0";
    std::cout << std::boolalpha;   
    std::cout<<s.isPalindrome(test);
}