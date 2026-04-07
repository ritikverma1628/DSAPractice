#include<iostream>
#include<vector>
using namespace std;


//INSTINCT --- you have to maintain the presence of each character added in result so that you can decide whether to include a charcter in the result.
string removeDuplicates(string &str){
    vector<bool> presence(26, false);
    string s="";
    for(int i = 0 ; i<str.size(); i++){
        if(!presence[str[i]-'a']){
            s+=str[i];
            presence[str[i]-'a']=true;
        }
    }
    return s;
}

int main()
{
    string str = "appnaccollege";
    cout<<removeDuplicates(str);
    return 0;
}