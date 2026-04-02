#include<iostream>
using namespace std;

void updateIthBit(int *num, int i , int value){
    *num = *num&~(1<<i);
    *num = *num|(value<<i);
}

int main()
{
    
    return 0;
}