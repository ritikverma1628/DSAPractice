#include<iostream>
#include<vector>
#include<string>
using namespace std;

void merge(vector<string> &words, int st, int mid, int end){
    int i = st;
    int j = mid+1;

    vector<string> temp;
    temp.reserve(end-st+1);

    while(i<=mid && j<=end){
        if(words[i]>words[j])
            temp.push_back(words[j++]);
        else
            temp.push_back(words[i++]);
    }

    while(i<=mid)
        temp.push_back(words[i++]);

    while(j<=end)
        temp.push_back(words[j++]);

    int k=0;
    for(int i = st; i<=end; i++){
        words[i] = temp[k++];
    } 
}

void mergeSortForAnArrayOfStrings(vector<string> &words, int st, int end){
    if(st>=end)
        return;

    int mid = (st+end)/2;

    mergeSortForAnArrayOfStrings(words, st, mid);
    mergeSortForAnArrayOfStrings(words, mid+1, end);

    if(words[mid]>words[mid+1])
        merge(words, st, mid, end);
}

int main()
{
    vector<string> words = {"sun","earth","mars","mercury"};
    mergeSortForAnArrayOfStrings(words, 0, words.size()-1);
    for(int i =0; i<words.size(); i++){
        cout<<words[i]<<" ";
    }
    return 0;
}