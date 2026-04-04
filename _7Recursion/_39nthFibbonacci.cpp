#include<iostream>
using namespace std;

int nthFibonacci(int n ){
    if(n==1 || n==2)
        return n-1;
    return nthFibonacci(n-1)+nthFibonacci(n-2);
}

int main()
{
    cout<<nthFibonacci(5);
    return 0;
}