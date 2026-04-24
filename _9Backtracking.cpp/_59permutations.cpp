#include<iostream>
using namespace std;

void permutations(string str,string permutation){
    if(str.length()==0){
        cout<<permutation<<" ";
        return;
    }

    for(int i = 0 ; i<str.size(); i++){
        permutations(str.substr(0, i)+str.substr(i+1, str.size()-i),permutation+str[i]);
    }
}

int main()
{
    string str = "abc";
    permutations(str, "");
    return 0;
}