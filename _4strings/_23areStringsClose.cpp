#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool closeStrings(string str1, string str2){
    if(str1.length()!=str2.length())
        return false;
    int freq1[26]={0};
    int freq2[26]={0};

    for(int i = 0 ; i<str1.length(); i++){
        freq1[str1[i]-'a']++;
        freq2[str2[i]-'a']++;
    }

    for(char ch: str2){
        if(freq1[ch-'a']==0)
            return false;
    }

    sort(freq1, freq1+26);
    sort(freq2, freq2+26);

    for(int i = 0 ; i<26 ; i++){
        if(freq1[i]!=freq2[i])
            return false;
    }

    return true;
}

int main()
{
    string str1 = "abbbccd";
    string str2 = "dddaabe";
    cout<<closeStrings(str1,str2);
    return 0;
}