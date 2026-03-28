#include <iostream>
using namespace std;

void transpose(int (*arr)[7], int rows, int cols){
    int mat[cols][rows];
    for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j<cols ; j++){
            mat[j][i]=arr[i][j];
        }
    }
    for(int i = 0 ; i<cols ; i++){
        for(int j = 0 ; j<rows; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[][7] = {{1,2,3,4,5,6,7},{1,2,3,4,5,6,7},{1,2,3,4,5,6,7}};
    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    transpose(arr, rows, cols);
}