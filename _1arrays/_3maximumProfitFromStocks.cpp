#include<iostream>
using namespace std;

int maxProfit(int arr[], int size){
    int maxPrice = 0;
    int maxProfit = 0 ;
    for(int i = size-1 ; i>=0 ; i--){
        if(i==size-1)
            maxProfit = -arr[i];
        else{
            maxPrice = max(maxPrice,arr[i+1]);
            maxProfit = max(maxProfit, maxPrice - arr[i]);
        }
    }
    if(maxProfit<0)
        return 0 ;
    return maxProfit;
}

int main(){
    int arr[] = {7,6,5,4,3,2 };
    cout<<maxProfit(arr, sizeof(arr)/sizeof(int));
}