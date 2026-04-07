#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------------------------

int tilingProblem(int n){
    if(n==1 || n==0)
        return 1;

    int hor = tilingProblem(n-1);
    int ver = tilingProblem(n-2);

    return hor+ver;
}

// ----------------------------------------------------------------------

int tileMemoHelper(int n, vector<int> &dp){   
    if(n==1 || n==0)
        return 1;

    if(dp[n]!=0)
        return dp[n];

    int hor = tileMemoHelper(n-1,  dp);
    int ver = tileMemoHelper(n-2, dp);

    return dp[n] = hor+ver;
}

int tileMemo(int n){
    vector<int> dp(n+1, 0);
    return tileMemoHelper(n, dp);
}
// -------------------------------------------------------------------

int tileTab(int n){
    if(n<=1)
        return 1;
    vector<int> dp(n+1);
    dp[0]=dp[1]=1;
    for(int i = 2; i<=n ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//-------------------------------------------------------------------

int spaceOptimisedTileTab(int n){
    if(n<=1)
        return 1;
    int prev1 = 1;
    int prev2 = 1;

    int curr;
    for(int i =2; i<=n ; i++){
        curr = prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}

int main()
{
    cout<<tilingProblem(6);
    return 0;
}