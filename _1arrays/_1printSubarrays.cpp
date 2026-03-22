#include<iostream>
using namespace std;

void printSubarrays1(int arr[], int n){
    for (int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<=n-i-1 ; j++){
            for (int k = j ; k<=i+j ; k++){
                cout<<arr[k]<<" ";
            }
            cout<<" , ";
        }
        cout<<endl;
    }
}

void printSubarrays2(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j<n-i ; j++){
            for(int k = i ; k<=i+j ; k++){
                cout<<arr[k]<<" ";
            }
            cout<<" , ";
        }
        cout<<endl;
    }
}

int main(){
    int array[] = {1,2,3,4,5};
    int n = sizeof(array)/sizeof(int);
    printSubarrays2(array,n);

}