#include<iostream>
#include<string>
using namespace std;

bool validAnagram(string str1, string str2){
    if(str1.length() != str2.length())
        return false;
    
    int freq[26] = {0};
    
    for(char ch: str2){
        freq[ch-'a']++;
    }

    for(char ch : str1){
        if(freq[ch-'a']==0)
            return false;
        freq[ch-'a']--;
    }
    return true;
}

int main()
{
    string str1 = "anagram" ;
    string str2 = "nggaram" ;
    cout<<validAnagram(str1, str2);
    
    return 0;
}