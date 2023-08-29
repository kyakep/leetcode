#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generate(n, n, "", result);
        return result;
    }
    
private:
    void generate(int open, int close, std::string current, std::vector<std::string>& result) {
        // Базовый случай: если количество открывающих и закрывающих скобок равно 0, то добавляем текущую комбинацию в результат
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        // Если еще есть незакрытые открывающие сскобки, то добавляем открывающую скобку и продолжаем генерацию
        if (open > 0) {
            generate(open - 1, close, current + '(', result);
        }

        // Если количество закрывающих скобок больше, чем открывающих, то добавляем закрывающую скобку и продолжаем генерацию
        if (close > open) {
            generate(open, close - 1, current + ')', result);
        }
    }
};

int main(){
    Solution s;
    std::cout<<s.generateParenthesis(3)<<std::endl;
}
/*we have count of opened and closed parenthesis. It putted while calling void recursive function
if number of closed and opened equal to zero, result will be pushed in vector
else if */