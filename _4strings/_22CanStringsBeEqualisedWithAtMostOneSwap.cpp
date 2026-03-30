#include<iostream>
#include<string>
using namespace std;

bool CanStringsBeEqualisedWithAtMostSwap(string str1, string str2){
    if(str1.length()!=str2.length())
        return false;
    
    int freq[26]={0};
    for(char ch:str1){
        freq[ch-'a']++;
    }

    for(char ch: str2){
        if(freq[ch-'a']==0)
            return false;
        freq[ch-'a']--;
    }
    int mismatchCount = 0;
    for(int i = 0 ; i<str1.length() ; i++){
        if(str1[i]!=str2[i]){
            mismatchCount++;
            if(mismatchCount>2)
                return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "ritik";
    string str2 = "iritk";
    cout<<CanStringsBeEqualisedWithAtMostSwap(str1, str2);
    return 0;
}