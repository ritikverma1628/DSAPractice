#include<iostream>
using namespace std;

int getIthBit(int num, int i ){
    return num&(1<<i)?1:0;
}

int main()
{
    cout<<getIthBit(9,3);
    return 0;
}