#include<iostream>
#include<vector>
using namespace std;

void ratInaMaze(vector<vector<int>> &plane, int n ,  int row, int col, string path){
    if(row==n-1 && col==n-1){
        cout<<path<<endl;
        return;
    }        

    if(col!=n-1 &&  plane[row][col+1]!=0)
        ratInaMaze(plane, n, row,col+1, path+'R');
    if(row!=n-1 && plane[row+1][col]!=0)
        ratInaMaze(plane, n, row+1, col, path+'D');
}

int main()
{
    vector<vector<int>> plane = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0},{0,1,1,1}};
    ratInaMaze(plane,4,0,0,"");
    return 0;
}