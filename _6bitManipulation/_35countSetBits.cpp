#include<iostream>
using namespace std;

int setBitsCount(int num){
    int count = 0 ;
    while(num>0){
        int temp = num ;
        if((temp&1)==1)
            count++;
        num = num>>1;
    }
    return count;
}

int main()
{
    cout<<setBitsCount(31);
    return 0;
}