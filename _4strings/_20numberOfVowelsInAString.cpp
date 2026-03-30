#include<iostream>
#include<string>
using namespace std;

int numberOfVowels(string &str){
    int count = 0 ;
    for(char ch:str){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' )
            count++;
    }
    return count;
}


int main()
{
    string str = "rioik";
    cout<<numberOfVowels(str);
    return 0;
}