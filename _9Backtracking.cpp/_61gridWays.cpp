#include<iostream>
#include<vector>
using namespace std;

int gridWays(int n ,int m, int row, int col ){
    if(row==n || col==m)
        return 0;
    if(row==n-1 && col==m-1)
        return 1;
    
    return gridWays(n, m , row, col+1)+gridWays(n, m , row+1, col);
}

int helper(vector<vector<int>> &dp, int n , int m , int row, int col){
    if(row==n || col==m)
        return 0;

    if(col==m-1 && row==n-1)
        return 1;

    if(dp[row][col]!=-1)
        return dp[row][col];

    return dp[row][col] = helper(dp, n, m , row, col+1) + helper(dp, n, m , row+1, col);
}

int gridWaysMemo(int n , int m , int row, int col){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(dp, n, m , row, col);
}

int gridWaysTab(int n , int m , int row, int col){
    vector<vector<int>> dp;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(i==0 && j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j] = dp[i][j-1];
            else if (j==0)
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }

}

int main()
{
    cout<<gridWays(3,3,0,0);
    return 0;
}