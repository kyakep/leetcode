/*Given a string s, return the longest 
palindromic substring in s.*/

#include <string>
#include <iostream>

bool isPal(std::string s, int i, int j) {
    int temp_i = j;
    while (i <= temp_i) {
        if (s[i] == s[j]) {
            i++; 
            j--;
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string ans;
        int n = 0;
        if (s.length() == 1){
            return s;
        }
        for (int i = 0; i <= s.length()-1; i++) {
            for (int j = s.length()-1; j >= i; j--) {
                if (j-i+1<ans.length()){
                    n++;
                    continue;
                }
                n++;
                if ((s[i] == s[j]) && (isPal(s, i, j))){
                    n--;
                    std::string temp = s;
                    temp.erase(temp.begin(), temp.begin()+i);
                    temp.erase(temp.end()-n, temp.end());
                    if (temp.length() > ans.length()) {
                        ans = temp;
                    }
                }
            }
            n = 0;
        }
        return ans;
    }
};
int main() {
    Solution s;
    std:: string str = "jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel";
    std:: string ans;
    std::cout<<s.longestPalindrome(str);

}