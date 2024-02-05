#include <string>

class Solution {
public:
    int findMinimumOperations(std::string s1, std::string s2, std::string s3) {
        int iter = 0, answer = -1;
        // if (s1.length() < 2 || s2.length() < 2 || s3.length() < 2){
        //     if (s1 == s2 && s1 == s3) {
        //         return 0;
        //     }
        //     return -1;
        // }
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i] && s1[i] == s3[i]){
                iter = i+1;
                answer = s1.length() - iter + s2.length() - iter + s3.length() - iter;
            }
            else {
                break;
            }
        }
        return answer;
    }
};

// int main(){
//     Solution solution;
//     solution.findMinimumOperations("abc", "abb", "ab");
// }