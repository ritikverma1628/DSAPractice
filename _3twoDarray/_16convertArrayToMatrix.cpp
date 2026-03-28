#include <iostream>
using namespace std;

void arrayToMatrix(int arr[], int size, int m , int n){
    if(size != (m*n)){
        cout<<"2D array not possible from given 1D array.";
        return;
    }
    int matrix[m][n];
    int index = 0 ;
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            matrix[i][j] = arr[index++];
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int m = 4;
    int n = 1;
    int size = sizeof(arr)/sizeof(arr[0]);
    arrayToMatrix(arr, size, m , n);
}