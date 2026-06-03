// leetcode 79

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Function declaration
bool dfs(vector<vector<char>>& board, int r, int c, string& word, int wordIndex);

bool wordSearch(vector<vector<char>>& board, string& word) {

    int rows = board.size();
    int cols = board[0].size();

    for(int r = 0; r < rows; r++) {

        for(int c = 0; c < cols; c++) {

            if(board[r][c] == word[0]) {

                if(dfs(board, r, c, word, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool dfs(vector<vector<char>>& board, int r, int c,
         string& word, int wordIndex) {

    // Base case
    if(wordIndex == word.size()) {
        return true;
    }

    int rows = board.size();
    int cols = board[0].size();

    // Boundary check
    if(r < 0 || c < 0 || r >= rows || c >= cols) {
        return false;
    }

    // Invalid case
    if(board[r][c] == ' ' ||
       board[r][c] != word[wordIndex]) {

        return false;
    }

    // Store original char
    char ch = board[r][c];

    // Mark visited
    board[r][c] = ' ';

    // Explore 4 directions
    if(dfs(board, r-1, c, word, wordIndex+1) ||
       dfs(board, r, c+1, word, wordIndex+1) ||
       dfs(board, r+1, c, word, wordIndex+1) ||
       dfs(board, r, c-1, word, wordIndex+1)) {

        return true;
    }

    // Backtracking
    board[r][c] = ch;

    return false;
}

int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    cout << wordSearch(board, word);

    return 0;
}