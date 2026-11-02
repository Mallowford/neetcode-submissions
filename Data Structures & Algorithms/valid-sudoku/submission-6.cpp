class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;
        map<pair<int, int>, unordered_set<char>> sub;

        for (int i = 0; i < board.size(); i++) { // Rows
            for (int j = 0; j < board.at(i).size(); j++) { // Cols
                if (board[i][j] == '.') {
                    continue;
                };

                char candidate = board.at(i).at(j);
                int r = i / 3;
                int c = j / 3;
                pair<int, int> p = make_pair(r, c);

                if (row[i].count(candidate) || col[j].count(candidate) || sub[p].count(candidate)) {
                    return false;
                };

                row[i].insert(candidate);
                col[j].insert(candidate);
                sub[p].insert(candidate);
            };
        };

        return true;
    };
};
