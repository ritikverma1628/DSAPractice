#include <iostream>
#include<climits>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0 ; i<size ; i++){
        cout<< arr[i]<<" ";
    }
}
void selectionSort(int arr[], int size){
    for(int i = 0 ; i< size-1 ; i++){
        int minimum = i;
        for(int j = i+1 ; j<size ; j++){
            if(arr[j]<arr[minimum])
                minimum = j ;
        }
        swap(arr[minimum], arr[i]);
    }
}

int main(){
    int arr[]={3,5,2,6,2,6};
    int size  = sizeof(arr)/sizeof(int);
    selectionSort(arr, size);
    printArray(arr, size);
}