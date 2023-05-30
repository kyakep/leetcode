#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        std::unordered_map<char, char> mp;
        int n=0;
        int last_ind=0;
        for (int i=0; i<t.length(); i++){
            mp[s[n]]=1; //заполнение мапы единицами
            if (s[n]==t[i] && i!=t.length()-1){ //
                n++;
                last_ind=i;
            }
            else if(s[n]==t[i] && i==t.length()-1)
                last_ind=i;
            if (n==s.length()-1 || s.length()==1){ //проверка последнего элемента, потому что да хз почему, просто сам факт
                for (int j=last_ind+1; j<t.length(); j++){
                     if (s[n]==t[i] && i!=t.length()-1){
                        n++;
                        break;
                    }
                    else if(s[n]==t[i] && i==t.length()-1)
                        break;
                }
            }
        }
        if (n==0) 
            n=-1;
        if (n+1==s.length()) 
            return true;
        return false;
    }
};


int main(){
    Solution s;
    std::cout<<s.isSubsequence("b","abc");
}

//нужна проверка последнего элемента стринга s