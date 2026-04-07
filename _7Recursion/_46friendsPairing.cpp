#include<iostream>
#include<vector>
using namespace std;

//INSTINCT--- whenever you are given two choices for the inputs , choose them and see if optimal substructures are coming ahead, now you know recursion dp mem tab etc
//---------------------------------------------------------------------------------------

int freindsPairingRec(int n ){
    if(n<=1)
        return 1;
    
    return freindsPairingRec(n-1)+((n-1)*freindsPairingRec(n-2));
}

//---------------------------------------------------------------------------------------

int freindsPairingMemHelper(int n, vector<int> &dp ){
    if(n<=1)
        return 1;
    
    if(dp[n]!=-1)
        return dp[n];
    
    return dp[n] = freindsPairingMemHelper(n-1, dp)+((n-1)*freindsPairingMemHelper(n-2, dp));
}

int freindsPairingMem(int n ){
    vector<int> dp(n+1, -1);
    return freindsPairingMemHelper(n, dp);
}

//---------------------------------------------------------------------------------------

int freindsPairingTab(int n ){
    if(n<=1)
        return 1;

    vector<int> dp(n+1, 0);
    dp[0]=1;
    dp[1]=1;

    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1]+(i-1)*dp[i-2];
    }
    
    return dp[n];
}

//---------------------------------------------------------------------------------------

int spaceOptimisedfreindsPairingTab(int n ){
    if(n<=1)
        return 1;
    
    int prev1 = 1;
    int prev2 = 1;

    int curr;
    for(int i =2 ; i<=n ; i++){
        curr = prev1 + (i-1)*prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}

//---------------------------------------------------------------------------------------




int main()
{
    cout<<spaceOptimisedfreindsPairingTab(3);
    return 0;
}