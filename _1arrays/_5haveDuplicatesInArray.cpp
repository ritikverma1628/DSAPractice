#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool haveDuplicates(int arr[], int size){
    vector<int> temp(arr, arr+size);
    sort(temp.begin(), temp.end());
    for(int i = 0 ; i<=size-2; i++){
        if(arr[i]==arr[i+1])
            return true;
    }
    return false;
}

int main(){
    int arr[] = {2,4,1,6,3,8};
    cout<<haveDuplicates(arr, sizeof(arr)/sizeof(int));
}