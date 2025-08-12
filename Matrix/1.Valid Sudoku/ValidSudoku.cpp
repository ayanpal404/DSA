#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, unordered_map<char, bool>> rowMap;
        unordered_map<int, unordered_map<char, bool>> colMap;

        for (int boxRow = 0; boxRow < n / 3; boxRow++) {
            for (int boxCol = 0; boxCol < n / 3; boxCol++) {

                unordered_map<char, bool> boxMap;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int row = boxRow * 3 + i;
                        int col = boxCol * 3 + j;

                        char val = board[row][col];
                        if (val == '.') continue;

                        if (boxMap[val]) return false;
                        boxMap[val] = true;

                        if (rowMap[row][val]) return false;
                        rowMap[row][val] = true;

                        if (colMap[col][val]) return false;
                        colMap[col][val] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool result = solution.isValidSudoku(board);
    if (result)
        cout << "The Sudoku board is valid." << endl;
    else
        cout << "The Sudoku board is NOT valid." << endl;

    return 0;
}
