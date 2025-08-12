# ✅ Valid Sudoku

Determine if a **9 x 9 Sudoku board** is valid based on the standard Sudoku rules:

🔗 **LeetCode Problem:** [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

## 📜 Problem Statement

A Sudoku board is valid if:

1. Each **row** contains the digits 1–9 without repetition.  
2. Each **column** contains the digits 1–9 without repetition.  
3. Each of the nine **3 × 3 sub-boxes** contains the digits 1–9 without repetition.  

> Only the **filled cells** (non-".") need to be validated.  
> A valid Sudoku board is not necessarily solvable.

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png"/>

---

## 🖼️ Examples

### Example 1
**Input:**
```
board = 
[["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]
```
**Output:**
``` true ```

---

### Example 2
**Input:**
```
board = 
[["8","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]
```


**Output:** ```false```

**Explanation:** Same as Example 1, except with the `5` in the top left corner being modified to `8`. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

---

## 🛠️ Approach

- **Use hash sets** to track seen numbers for:
  - Rows
  - Columns
  - Sub-boxes (indexed using `(row/3, col/3)`)
- For each filled cell:
  1. Check if the number already exists in the row, column, or sub-box.
  2. If yes → invalid board.
  3. Otherwise, add it to the corresponding set.
- Return `true` if no conflicts are found.

<!-- ---

## ⏳ Time Complexity
- **O(1)** — The board size is fixed at 9×9, so operations are constant time.

## 💾 Space Complexity
- **O(1)** — Uses fixed-size sets for rows, columns, and boxes.

--- -->

<!-- ## 💻 Solution Code

```cpp
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    string rowKey = "row" + to_string(i) + num;
                    string colKey = "col" + to_string(j) + num;
                    string boxKey = "box" + to_string(i/3) + to_string(j/3) + num;
                    
                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey))
                        return false;
                    
                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }
        return true;
    }
}; -->