#include<iostream>
#include<vector>
using namespace std;

//dp will be used if it asks the number of strings, but as the problem ask for printing the strings, this recursion is optimal.

//INSTINCT -- the optimal substructures depend on local state, so you have to think about that state and move forward keeping in mind the state and constraint given 
void printBinaryStrings(int n, string ans){
    if(ans.size()==n){
        cout<<ans<<endl;
        return;
    }

    printBinaryStrings(n, ans+'0');

    if(ans[ans.size()-1]!='1'){
        printBinaryStrings(n, ans+'1');
    }    
}

// -------------------------------------------------------------------------------

int numberOfBinaryStrings(int n, int lastplace){
    if(n==1){
        if(lastplace==1)
            return 1;
        else if(lastplace==0)
            return 2;
    }
    int ways = 0;
    ways+= numberOfBinaryStrings(n-1, 0);
    if(lastplace!=1)
        ways+= numberOfBinaryStrings(n-1, 1);

    return ways;
}

// --------------------------------------------------------------------------------

int helper(int n, int lastplace, vector<vector<int>>&dp){
    if(n==0){
        return 0;
    }
    if(n==1){
        if(lastplace==1)
            return 1;
        else if(lastplace==0)
            return 2;
    }
    
    if(dp[n][lastplace]==0){
        int ways=0;
        ways+= helper(n-1, 0, dp);
        if(lastplace!=1)
            ways+= helper(n-1, 1, dp);

        dp[n][lastplace]=ways;
    }

    return dp[n][lastplace];
}

int numberOfBinaryStringsMemo(int n, int lastplace){
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    return helper(n, lastplace, dp);
}

// -----------------------------------------------------------------------------

int numberOfBinaryStringsTab(int n, int lastplace){
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[1][0] = 2;
    dp[1][1] = 1;

    for(int i =2; i<=n; i++){  
        dp[i][0] = dp[i-1][0]+dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    return dp[n][lastplace];
}

int main()
{
    cout<<numberOfBinaryStringsTab(4, 0);
    return 0;
}