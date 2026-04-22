#include<iostream>
using namespace std;

void subsets(string str, int n, string subset){
    if(n==str.length()){
        cout<<subset<<" ";
        return;
    }

    subsets(str, n+1, subset+str[n]);
    subsets(str, n+1, subset);
}

int main()
{
    string str ="abc";
    subsets(str, 0, "");
    return 0;
}