#include<iostream>
using namespace std;

bool isPowerOf2(int num){
    return num&(num-1)?0:1;
}

int main()
{
    cout<<isPowerOf2(8);
    return 0;
}