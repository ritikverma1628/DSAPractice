#include<iostream>
using namespace std;

int trappedRainwater(int blocks[], int size){
    int amount = 0 ;
    int leftMax[size]={0};
    int rightMax[size]={0};

    for(int i = 1 ; i < size-1 ; i++){
        leftMax[i] = max(leftMax[i-1], blocks[i-1]);
        rightMax[size-i-1] = max(rightMax[size-i], blocks[size-i]);
    }

    for(int i = 1 ; i < size-1 ; i++){
        if(min(leftMax[i], rightMax[i]) > blocks[i])
            amount += (min(leftMax[i], rightMax[i]) - blocks[i]) ;    
    }

    return amount;
}

int main(){
    int blocks[] = {4,2,0,6,3,2,5};
    cout<<trappedRainwater(blocks, sizeof(blocks)/sizeof(int));

}