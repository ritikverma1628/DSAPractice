#include<iostream>
#include<vector>
using namespace std;

//this is a variation in which you have to insert the number in the cell where knight visits as the number of its visit 

bool knightTour(vector<vector<int>> &board, int n, int row, int col, int cellsTraversed){
    if(row>=n || row<0 || col<0 || col>=n)
        return false;
    if(board[row][col]!=0)
    return false;
    
    board[row][col]=cellsTraversed;
    if(cellsTraversed == n*n){
        cout<<"solutions exists";
        return true;
    }
    if(knightTour(board,n, row-2, col-1, cellsTraversed+1)) return true;
    if(knightTour(board,n, row-2, col+1, cellsTraversed+1)) return true;
    if(knightTour(board,n, row+2, col-1, cellsTraversed+1)) return true;
    if(knightTour(board,n, row+2, col+1, cellsTraversed+1)) return true;
    if(knightTour(board,n, row-1, col+2, cellsTraversed+1)) return true;
    if(knightTour(board,n, row+1, col+2, cellsTraversed+1)) return true;
    if(knightTour(board,n, row-1, col-2, cellsTraversed+1)) return true;
    if(knightTour(board,n, row+1, col-2, cellsTraversed+1)) return true;
    
    board[row][col]=0;
    return false;
}

int main()
{
    vector<vector<int>> board(8, vector<int>(8,0));
    cout<<knightTour(board, board.size(), 0, 0, 1);
    return 0;
}