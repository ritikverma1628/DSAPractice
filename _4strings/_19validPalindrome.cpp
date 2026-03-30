#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char str[], int length){
    int start = 0 ; 
    int end = length-1;
    while(start<end){
        if(str[start] != str[end] )
            return false;
        start++;
        end--;
    }
    return true;
}

int main()
{
    char str[] = "abba";
    // cout<<isPalindrome(str, strlen(str));
    cin.getline(str,30);
    cout<<str;
    return 0;
}