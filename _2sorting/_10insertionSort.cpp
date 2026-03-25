#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0 ; i<size ; i++){
        cout<< arr[i]<<" ";
    }
}
void insertionSort(int arr[], int size){
    for(int i = 1 ; i<size ; i++){
         
        for(int j = i-1; j>=0; j--){
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
            else
                break;       
        }
    }
}

int main(){
    int arr[]={3,5,2,6,2,6};
    int size  = sizeof(arr)/sizeof(int);
    insertionSort(arr, size);
    printArray(arr, size);
}