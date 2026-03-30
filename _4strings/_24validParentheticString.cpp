#include<iostream>
#include<string>
using namespace std;

bool isValidParentheticString(string str){
    int opening = -1 ;
    while(!str.empty()){
        if(opening==-1 && (str[opening+1]==']' || str[opening+1]==')' || str[opening+1]=='}'))
            return false;
        while(str[opening+1]!='}'  && str[opening+1]!=']' && str[opening+1]!=')'){
            opening++;
            if(opening==str.length())
                return false;
        }
        if(str[opening]=='(' && (str[opening+1]=='}' || str[opening+1]==']'))
            return false;
        else if(str[opening]=='[' && (str[opening+1]=='}' || str[opening+1]==')'))
            return false;
        else if(str[opening]=='{' && (str[opening+1]==')' || str[opening+1]==']'))
            return false;
        str = str.substr(0, opening)+str.substr(opening+2,str.length()-1-(opening+1));
        opening--;
    }
    return true;
}

int main()
{
    string str = "(";
    cout<<isValidParentheticString(str);
    return 0;
}