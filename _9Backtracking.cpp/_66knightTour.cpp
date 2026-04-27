#include<iostream>
#include<vector>
using namespace std;


bool knightTour(vector<vector<int>> &board, int row, int col, int expectedValue){
    if(row<0 ||col<0 || col>=board.size() ||row>=board.size())
        return false;
    if(expectedValue==board.size()*board.size()-1 && board[row][col]==expectedValue)
        return true;

    if(board[row][col]!=expectedValue)
        return false;

    else{
        if(knightTour(board, row-2, col-1, expectedValue+1)) return true;
        if(knightTour(board, row-2, col+1, expectedValue+1)) return true;
        if(knightTour(board, row+2, col-1, expectedValue+1)) return true;
        if(knightTour(board, row+2, col+1, expectedValue+1)) return true;
        if(knightTour(board, row-1, col+2, expectedValue+1)) return true;
        if(knightTour(board, row+1, col+2, expectedValue+1)) return true;
        if(knightTour(board, row-1, col-2, expectedValue+1)) return true;
        if(knightTour(board, row+1, col-2, expectedValue+1)) return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> board ={{0,3,6},{5,8,1},{2,7,4}};
    cout<<knightTour(board, 0,0,0);
    return 0;
}