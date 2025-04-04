class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> rowMap, colMap, gridMap;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int number = board[i][j] - '0';
                    int gridIndex = (i / 3) * 3 + (j / 3);
                    if (rowMap[i][number]++ > 0 || colMap[j][number]++ > 0 || gridMap[gridIndex][number]++ > 0)
                        return false;
                }
            }
        }
        return true;
    }
};
