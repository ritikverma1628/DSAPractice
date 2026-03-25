#include<iostream>
using namespace std;

int searchInRotatedSortedArray(int arr[], int size, int key){
    int start = 0 ;
    int end = size-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[start]<arr[mid]){
            if(arr[start] <= key && key <= arr[mid])
                end = mid-1;
            else
                start=mid+1;
        }
        else{
            if(arr[mid]<=key && key<=arr[end])
                start=mid+1;
            else
            end=mid-1;
        }       
    }
    return -1;
}

int main(){
    int arr[]={4,5,6,7,0,1,2};
    cout<<searchInRotatedSortedArray(arr, sizeof(arr)/sizeof(int), 6);
}