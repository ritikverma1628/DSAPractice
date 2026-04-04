#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){
    
    if(size==1 || size==0)
        return true;

    if(!isSorted(arr, size-1))
        return false;
    return arr[size-1]>=arr[size-2];
        
}

int main()
{
    int arr[] = {1,2,6,4,5};
    cout<<isSorted(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}