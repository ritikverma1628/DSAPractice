#include<iostream>
using namespace std;

void clearLastIBits(int *num, int i ){
    *num = *num&((~0)<<i);
}

int main()
{
    int num = 23;
    clearLastIBits(&num, 3);
    cout<<num;
    return 0;
}