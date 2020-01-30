class Solution {
public:
    bitset<9> rows[9], cols[9], squares[3][3];
    void solveSudoku(vector<vector<char>>& board) {
        // init
        for (int i=0;i<9;i++){
            rows[i].set();
            cols[i].set();
            squares[i/3][i%3].set();
        }
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++) {
                if (board[i][j]!='.') {
                    rows[i].set(board[i][j]-'1', false);
                    cols[j].set(board[i][j]-'1', false);
                    squares[i/3][j/3].set(board[i][j]-'1', false);
                }
            }
        }
        solveSudoku_(board, 0, 0);
    }
    int solveSudoku_(vector<vector<char>>& board, int i, int j) {
        while (1) {
            if (i==8 && j==8 && board[i][j]!='.') return 1;
            if (j==9) {
                i++; j=0;
            }
            if (board[i][j]!='.') {
                j++; continue;
            }
            break;
        }
        bitset<9> available;
        available = rows[i] & cols[j] & squares[i/3][j/3];
        // Check for available value
        for (int k='1';k<='9';k++){
            if (available[k-'1']) {
                board[i][j]=k;
                rows[i].set(k-'1', false);
                cols[j].set(k-'1', false);
                squares[i/3][j/3].set(k-'1', false);
                
                if (i==8 && j==8) return 1;
                int result = solveSudoku_(board, i, j+1);
                if (result) return 1;
                
                rows[i].set(k-'1');
                cols[j].set(k-'1');
                squares[i/3][j/3].set(k-'1');
            }
        }
        board[i][j] = '.';
        return 0;
    }
};