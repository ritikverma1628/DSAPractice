#include<iostream>
#include<string>
#include<vector>
using namespace std;

// given a string, we have to return the count of substrings in s which start and end with same character


int numOfSubstrings(string s){
    int count = 0 ;
    for(int i = 0 ; i<s.size(); i++){
        for(int j = 0 ; j<s.size()-i; j++){
            if(s[i]==s[i+j])
                count++;
        }
    }
    return count;  
}

int numOfSubstrings2(string str){
    int n = str.size();
    vector<int> freq(26,0);

    for(int i=0; i<n; i++){
        freq[str[i]-'a']++;
    }

    int count=0;
    for(int i = 0 ; i<freq.size();i++){
        if(freq[i]>1){
            count=count+(freq[i]*(freq[i]-1))/2;
        }
    }
    return count+n;
}

int main()
{
    string str = "abcab";
    cout<<numOfSubstrings2(str);
    return 0;
}