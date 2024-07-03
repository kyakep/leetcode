// Completed

/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

  Each row must contain the digits 1-9 without repetition.
  Each column must contain the digits 1-9 without repetition.
  Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> statesRow(9, vector<bool>(9, 0));
    vector<vector<bool>> statesCol(9, vector<bool>(9, 0));
    vector<vector<bool>> statesSquare(9, vector<bool>(9, 0));

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == '.') {
          continue;
        }
        int currentNum = board[i][j] - '0';
        cout<<board[i][j]<<" "<<currentNum<<" ";
        if (statesRow[i][currentNum - 1] == 1 || 
            statesCol[j][currentNum - 1] == 1 || 
            statesSquare[int(i / 3) + 3 * int(j / 3)][currentNum - 1] == 1) 
        {
          return false;
        }
        else {
          statesRow[i][currentNum - 1] = 1;
          statesCol[j][currentNum - 1] = 1; 
          statesSquare[int(i / 3) + 3 * int(j / 3)][currentNum - 1] = 1;
        }
      }
    }

    return true;
  }
};

int main() {
  Solution sol;

  vector<vector<char>> test {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

  cout<<sol.isValidSudoku(test);
}