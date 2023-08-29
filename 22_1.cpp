#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generateCombination(result, "", n, 0, 0);
        return result;
    }

    void generateCombination(std::vector<std::string>& result, std::string current, int n, int open, int close) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            generateCombination(result, current + '(', n, open + 1, close);
        }

        if (close < open) {
            generateCombination(result, current + ')', n, open, close + 1);
        }
    }
};

int main() {
    Solution sol;
    int n = 3;
    std::vector<std::string> combinations = sol.generateParenthesis(n);
    for (const auto& combination : combinations) {
        std::cout << combination << std::endl;
    }
    return 0;
}
