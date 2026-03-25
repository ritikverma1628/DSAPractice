#include <iostream>
#include <climits>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0 ; i<size ; i++){
        cout<< arr[i]<<" ";
    }
}
void countingSort(int arr[], int size){
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    for(int i = 0 ; i< size ; i++){
        minValue = min(minValue, arr[i]);
        maxValue = max(maxValue, arr[i]);
    }
    int freq[maxValue+1]={0};
    for(int i = 0 ; i<size ; i++){
        freq[arr[i]]++;
    }
    int index = 0 ;
    for(int i = minValue; i<=maxValue; i++){
        while(freq[i]!=0){
            arr[index] = i;
            index++;
            freq[i]--;
        }
    }
}

int main(){
    int arr[]={3,5,2,6,2,6};
    int size  = sizeof(arr)/sizeof(int);
    countingSort(arr, size);
    printArray(arr, size);
}