class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], columns[9], boxes[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c == '.') continue;
                if(rows[i].count(c)) return false;
                rows[i].insert(c);
                if(columns[j].count(c)) return false;
                columns[j].insert(c);
                int index = (i/3)*3 + (j/3);
                if(boxes[index].count(c)) return false;
                boxes[index].insert(c);
            }
        }

        return true;
    }
};
