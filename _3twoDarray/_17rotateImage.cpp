//given 2D array and we have to rotate it by 90 degree assuming it to be applicable on the rotating of an image 
//have to do it in-place

#include <iostream>
using namespace std;

void print2DArray(int arr[][3], int rows, int cols){
    for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j<cols ; j++){
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotateImage(int arr[][3], int dimension){
    for(int i = 0 ; i<dimension ;i++){
        for(int j = i+1 ; j<dimension ; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i = 0 ; i<dimension ; i++){
        for(int j = 0 ; j<(dimension/2) ; j++){
            swap(arr[i][j], arr[i][dimension-j-1]);
        }
    }
}

int main(){
    int arr[][3] = {{1,2,3},{5,6,7},{9,10,11}};
    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    rotateImage(arr, rows);
    print2DArray(arr, rows, cols);
}