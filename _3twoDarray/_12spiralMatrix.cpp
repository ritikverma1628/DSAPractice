#include <iostream>
using namespace std;

void spiralMatrix(int arr[][7], int rows, int cols){
    int sc = 0;
    int sr = 0;
    int er = rows-1;
    int ec = cols-1;

    while(sr<=er && sc<=ec){    

        for(int i = sc ; i<=ec ; i++){
            cout<<arr[sr][i]<<" ";
        }
        sr++;

        if(sr<=er && sc<=ec){
        for(int i = sr ; i<=er ; i++){
            cout<<arr[i][ec]<<" ";
        }}
        ec--;

        if(sr<=er && sc<=ec){ 
            for(int i = ec ; i>=sc ; i--){
                cout<<arr[er][i]<<" ";
            }
            er--;
        }

        if(sc<=ec && sr<=er){
            for(int i = er ; i>=sr ; i--){
                cout<<arr[i][sc]<<" ";
            }
            sc++;
        }
    }
}

int main(){
    int arr[][7] = {{1,2,3,4,5,6,7},{1,2,3,4,5,6,7},{1,2,3,4,5,6,7}};
    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    // cout<<rows<<" "<<cols;
    spiralMatrix(arr,rows, cols);

}