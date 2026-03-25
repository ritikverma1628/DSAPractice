#include <iostream>
#include <climits>
using namespace std;

int maximumProductSubarray(int arr[], int size){
    int maximumProduct = INT_MIN;
    int currentPrefixProduct = 1;
    int currentSuffixProduct = 1;

    for(int i = 0; i<size ; i++){
        currentPrefixProduct*=arr[i];
        currentSuffixProduct*=arr[size-i-1];

        maximumProduct = max(maximumProduct, max(currentPrefixProduct, currentSuffixProduct));

        if(currentPrefixProduct==0)
            currentPrefixProduct=1;
        if(currentSuffixProduct==0)
            currentSuffixProduct=1;
    }
    return maximumProduct;
}

int main(){
    int arr[] = {-2,-1};
    int size = sizeof(arr)/sizeof(int);
    cout<<maximumProductSubarray(arr, size);
}