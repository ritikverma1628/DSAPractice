//the matrix is sorted row wise as well as column wise
// the search can be done in brute force approach one by one element peeking
// row wise or column wise binary search
// staircase search

#include <iostream>
using namespace std;

int staircaseSearch(int arr[][4], int rows, int cols, int key){
    int col = cols-1;
    int row = 0;

    while(row<rows && col>=0){
        if(arr[row][col] == key)
            return true;
        else if(arr[row][col]<key)
            row++;
        else 
            col--;
    }
    return false;
}
int main(){
    int arr[][4] = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    cout<<staircaseSearch(arr, rows, cols,31);
}