#include<iostream>
using namespace std;

void setIthBit(int *num , int i ){
    *num = *num|1<<i;
}

int main()
{
    int num = 9;
    setIthBit(&num,1);
    cout<<num;
    return 0;
}