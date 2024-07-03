/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

bool check (std::vector<char> wh){
    std::unordered_map<char, int> raw;
    for (int i = 0; i < wh.size(); i++) {
        raw[wh[i]]++;
        if (raw[wh[i]]>1){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char> >& board) {
        std::vector<char> wh;
        int raw = 0, board_depth = board.size(), board_length = board[0].size();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] !=  '.'){
                    wh.push_back(board[i][j]);
                }
                if (check(wh)==false) {
                    return false;
                }
            }
            wh.clear();
        }
        for (int j = 0; j < board_length; j++){
            while (raw<board_length){
                if (board[raw][j] !=  '.'){
                    wh.push_back(board[raw][j]);
                }
                raw++;
            }
            if (check(wh)==false) {
                return false;
            }
            raw=0;
            wh.clear();
        }
        for (int i = 0; i < board_length; i+=3){
            std::cout<<"1"<<std::endl;
            for (int j = 0; j < board_depth; j+=3){
                std::cout<<"2"<<std::endl;
                for (int si = i; si < i+3; si++){
                    std::cout<<"3"<<std::endl;
                    for (int sj = j; sj < j+3; sj++){
                        std::cout<<"4"<<std::endl;
                        if (board[si][sj] !=  '.'){
                            wh.push_back(board[si][sj]);
                        }             
                    }
                }
                if (check(wh)==false) {
                    return false;
                }
                wh.clear();
            }
        }
        return true;
    };
};

int main(){
    std::vector<std::vector<char> > test {{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
    { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
    { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
    { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
    { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
    { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
    { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
    { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
    { '.', '.', '.', '.', '8', '.', '.', '7', '9' }};
    Solution s;
    std::cout << std::boolalpha; 
    std::cout<<s.isValidSudoku(test);
}