#include<iostream>
#include<vector>
using namespace std;

void printQueenPlaces(vector<vector<char>> &board, int n){
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------  ";   
}



bool isSafe(vector<vector<char>> &board, int row, int col){
    //horizontal check --- unnecessary cz we are already placing '.' in place 'Q' while backtracking
    // for(int i = 0 ; i<col ; i++){
    //     if(board[row][i]=='Q')
    //         return false;
    // }

    //vertical check
    for(int i = 0; i<row; i++){
        if(board[i][col]=='Q')
            return false;
    }

    //diagonal check towards left
    int c = col-1;
    int r = row-1;
    while(c>=0 && r>=0){
        if(board[r][c]=='Q')
            return false;
        c--;
        r--;
    }

    //diagonal check towards right
    r=row-1;
    c=col+1;
    while(c<board.size() && r>=0){
        if(board[r][c]=='Q')
            return false;
        c++;
        r--;
    }

    return true;
}

void helper(vector<vector<char>> &board, int row, int n){
    if(row==n){
        printQueenPlaces(board, n);
        return;
    }

    for(int i=0 ; i<n ; i++){    
            if(isSafe(board, row, i)){
                board[row][i]='Q';
                helper(board, row+1, n);
                board[row][i]='.';
            }
    }
}

void Nqueens(int n){
    vector<vector<char>> board(n, vector<char>(n,'.'));
    helper(board, 0, n);
}

int main()
{
    Nqueens(4);
    return 0;
}