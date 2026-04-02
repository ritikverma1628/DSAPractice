#include<iostream>
using namespace std;

bool isEven(int num){
    return num&1==1?false:true;
}

int main()
{
    cout<<isEven(49)<<endl;
    cout<<isEven(50)<<endl;
    cout<<isEven(51)<<endl;
    cout<<isEven(52)<<endl;
    cout<<isEven(53)<<endl;
    return 0;
}