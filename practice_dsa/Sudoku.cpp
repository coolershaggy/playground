#pragma once
#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>
using namespace std;

//IMP for sudoku
/*
if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == ch) {
    return false;
}
if (board[(3 * row) / 3 + i / 3][(3 * col) / 3 + i % 3] == ch) {
    return false;
}
*/

class Solution {
public:
    bool isSafeForSudoku(int row, int col, vector<vector<char>>& board, char& ch) {
        //char ch = val + '0';
        for (int i = 0; i < board.size(); i++)
        {
            //check all columns in row
            if (board[row][i] == ch) {
                return false;
            }
            //check all rows in column
            if (board[i][col] == ch) {
                return false;
            }
            //check 3*3 matrix
            //make sure we follow BODMAS so use bracket for division below. If we mess up this answer will be wrong
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) {
                return false;
            }
        }
        return true;
    }

    bool solveMySudoku(vector<vector<char>>& board) {
        // size of board. We know its 9 but still
        int size = board[0].size();

        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                //'.' means position is empty and we can start solving it for '.'
                if (board[row][col] == '.') {
                    /*
                    for (int val = 1; val < 10; val++) {
                        if (isSafeForSudoku(row, col, board, val)) {
                            board[row][col] = val + '0';
                            bool nextPossibleSolution = solveMySudoku(board);
                            if (nextPossibleSolution == true) {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    */
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafeForSudoku(row, col, board, val)) {
                            board[row][col] = val;
                            //bool nextPossibleSolution = solveMySudoku(board);
                            if (solveMySudoku(board)) {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool canWeSolveIt = solveMySudoku(board);
    }
};