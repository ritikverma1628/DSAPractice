#include<iostream>
using namespace std;

void uppercaseIt(char str[]){
    int i = 0 ;
    while(str[i]!='\0'){
        if(str[i]>='a' && str[i]<='z')
            str[i]=(char)(str[i]-32);
        i++;
    }
}

int main()
{
    char str[] = "riTik";
    uppercaseIt(str);
    cout<<str;
    return 0;
}