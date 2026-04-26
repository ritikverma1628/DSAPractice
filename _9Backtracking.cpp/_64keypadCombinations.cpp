#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void helper(string str, int index, unordered_map<char, vector<char>> map, string combinations){
    if(combinations.length()==str.length()){
        cout<<combinations<<endl;
        return;
    }
    
    for(char ch : map[str[index]]){
        helper(str,index+1, map, combinations+ch);
    }
}

void keypadCombinations(string str){
    unordered_map<char, vector<char>> map;
    map['2']={'a','b','c'};
    map['3']={'d','e','f'};
    map['4']={'g','h','i'};
    map['5']={'j','k','l'};
    map['6']={'m','n','o'};
    map['7']={'p','q','r','s'};
    map['8']={'t','u','v'};
    map['9']={'w','x','y','z'};

    helper(str, 0, map, "");
}

int main()
{
    string str = "29";
    keypadCombinations(str);
    return 0;
}