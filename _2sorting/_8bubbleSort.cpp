#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0 ; i<size ; i++){
        cout<< arr[i]<<" ";
    }
}
void bubbleSort(int arr[], int size){
    for(int i = 0 ; i< size-1 ; i++){
        for(int j = 0 ; j < size-i-1 ; j++){
        if(arr[j]>arr[j+1])
            swap(arr[j], arr[i+1]);
        }
    }
}

int main(){
    int arr[]={3,5,2,6,2,6};
    int size  = sizeof(arr)/sizeof(int);
    bubbleSort(arr, size);
    printArray(arr, size);
}