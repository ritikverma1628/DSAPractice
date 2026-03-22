#include<iostream>
#include<climits>
using namespace std;

//approach1 of n^3 tc
int maxSubarraySum(int arr[], int n){
    int maxSum = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j<n-i ; j++){
            int sum = 0 ;
            for(int k = i ; k<=i+j ; k++){
                sum+=arr[k];
            }
            maxSum = max(sum, maxSum);
        }   
    }
    return maxSum;
}

//approach2 of n^2 tc
int maxSubarraySum2(int arr[], int n){
    int maxSum = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j<n-i ; j++){
            sum+=arr[i+j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

//kadane's algorithm for maximum subarray sum 
int maxSubarraySum3(int arr[], int n){
    int maxSum = INT_MIN ;
    int currSum = 0 ;
    for(int i = 0 ; i < n ; i++){
        currSum+=arr[i];
        maxSum= max(maxSum, currSum);
        if(currSum<0)
            currSum=0;
    }
    return maxSum;
}

int main(){
    int arr[] = {2,-3,6,-5,4,2};
    cout<<maxSubarraySum3(arr, sizeof(arr)/sizeof(int));
}