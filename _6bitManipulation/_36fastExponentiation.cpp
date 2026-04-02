#include<iostream>
using namespace std;

int fastExpo(int base, int power){
    int ans = 1;
    int b = base;
    while(power>0){
        int lastBit = power&1;
        if(lastBit==1)
            ans*=b;
        b*=b;
        power=power>>1;
    }
    return ans;
}

int main()
{
    cout<<fastExpo(3, 4);
    return 0;
}