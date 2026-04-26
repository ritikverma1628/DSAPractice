#include <iostream>
#include <vector>
using namespace std;

void printSudoku(vector<vector<int>> & board){
    int n = board.size();
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    } 
}

bool isSafe(vector<vector<int>> &board, int row, int col, int value){
    int n = board.size();
    for(int i=0 ; i<n; i++){
        if(board[i][col]==value || board[row][i]==value) //vertial||horizontal
            return false;
    }

    int r = row/3;
    int c = col/3;

    for(int i = 3*r; i<3*r+3; i++){
        for(int j = 3*c ; j<3*c+3 ; j++){
            if(board[i][j]==value)
                return false;
        }
    }
    return true;
}

void sudokuSolver(vector<vector<int>> &board, int n, int row, int col ){
    if(row==n){
        printSudoku(board);
        return;
    }

    if(board[row][col]!=0){
        if(col==n-1)
                sudokuSolver(board, n, row+1, 0);
        else
            sudokuSolver(board, n, row, col+1);
    }

    else{
        for(int i = 1 ; i<=n ; i++){
            if(isSafe(board, row, col, i)){
                board[row][col]=i;
                if(col==n-1)
                    sudokuSolver(board, n, row+1, 0);
                else
                    sudokuSolver(board, n, row, col+1);
                board[row][col]=0;
            }
        }
    }  
}

int main()
{
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    sudokuSolver(board, 9, 0, 0);
    return 0;
}