#include<iostream>
using namespace std;

int exponentiation(int base, int power){
    if(power == 0)
        return 1;
    
    int value = exponentiation(base, power/2);

    if(power%2==0)
        return value*value;
    else
        return value*value*2;
}

int main()
{
    cout<<exponentiation(2,10);

    return 0;
}