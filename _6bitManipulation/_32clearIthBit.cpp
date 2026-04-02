#include<iostream>
using namespace std;

void clearIthBit(int * num , int i ){
    int bitmask = ~(1<<i);
    *num = *num&bitmask;
}

int main()
{
    int num = 5;
    clearIthBit(&num, 0);
    cout<<num;
    return 0;
}