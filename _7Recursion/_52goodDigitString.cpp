#include<iostream>
using namespace std;

long long mod =1e9+7;

long long fastExpo(int base, int power){
    long long ans = 1;
    long long b = base;
    while(power>0){
        
        if(power&1)
            ans=(ans*b)%mod;
        b=(b*b)%mod;
        power=power>>1;
    }
    return ans;
}

//a good 'digit string' is a string made up of digits from 0 to 9 when the digits at even index are even digits and the digits at odd indices are prime number
long long goodDigitString(long long n){
    return (fastExpo(5,(n+1)/2) * fastExpo(4,n/2))%mod; 
}

int main()
{
    cout<<goodDigitString(1);
    return 0;
}