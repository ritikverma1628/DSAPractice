#include <iostream>
using namespace std;

int diagonalSum(int arr[][3], int dimension){
    int sum =0;
    for(int i = 0 ; i<dimension ; i++){
        sum+=arr[i][i];
        int j = dimension-i-1;
        if(i!=j)
            sum+=arr[i][j];
    }
    return sum;
}


int main(){
    int arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int dimension =  sizeof(arr[0])/sizeof(arr[0][0]);
    cout<<diagonalSum(arr,dimension);
}