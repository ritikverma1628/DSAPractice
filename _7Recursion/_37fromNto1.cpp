#include<iostream>
using namespace std;

void fromNto1(int n ){
    if(n==0)
    return;

    cout<<n; //from n to 1
    fromNto1(n-1);
    cout<<n; //from 1 to n 
}

int main()
{
    fromNto1(7);
    return 0;
}