#pragma once
#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>
using namespace std;

class Solution {
public:
    void addBoardToAns(vector<vector<string>>& answer, vector<vector<string>>& board, int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            //this manipulation took me time
            //i was getting answer as characters but solution needed string
            //What i got: {".","Q",".","."}
            //what solution here wants: {"..Q.",}
            //hence appending my answer in string and then pushing that to answer
            string row = "";
            for (int j = 0; j < n; j++)
            {
                row += board[i][j];

            }
            temp.push_back(row);
        }
        answer.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<string>>& board, int n) {
        int x = row;
        int y = col;

        //we are adding queens by columns so we will check only for previously added col position

        //same row
        while (y >= 0)
        {
            if (board[x][y] == "Q") {
                return false;
            }
            y--;
        }
        //reset x,y
        x = row;
        y = col;
        //diagonal up
        while (y >= 0 && x >= 0)
        {
            if (board[x][y] == "Q") {
                return false;
            }
            y--;
            x--;
        }
        //reset x,y
        x = row;
        y = col;
        //diagonal down
        while (y >= 0 && x < n)
        {
            if (board[x][y] == "Q") {
                return false;
            }
            y--;
            x++;
        }

        //jar ithe paryant alo mhanje safe aahe
        return true;

    }
    void queen(int col, vector<vector<string>>& answer, vector<vector<string>>& board, int n) {
        //base case
        if (col == n) {
            //add current board positions to answer vector
            addBoardToAns(answer, board, n);
            return;
        }
        //if( n <=3 && n!=1)
        //{
        //    return;
        //}
        //solve for one case of first col
        //go for all rows in first col
        for (int row = 0; row < n; row++)
        {
            //check if its safe to place queen on this column
            if (isSafe(row, col, board, n)) {
                board[row][col] = "Q";
                queen(col + 1, answer, board, n);
                board[row][col] = "."; //bracktrack if not the right position
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        //create board, initialize it to N
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> answer;
        //start with Column 0
        queen(0, answer, board, n);
        return answer;
    }
};