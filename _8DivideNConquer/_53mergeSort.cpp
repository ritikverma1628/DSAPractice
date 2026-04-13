#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, int st, int mid, int end){
    int i = st;
    int j =mid+1;

    vector<int>temp;
    temp.reserve(end-st+1);

    while(i<=mid && j<=end){
        if(nums[i]<nums[j])
            temp.push_back(nums[i++]);
        else
            temp.push_back(nums[j++]);
    }

    while(i<=mid)
        temp.push_back(nums[i++]);

    while(j<=end)
        temp.push_back(nums[j++]);

    int k=0;
    for(int i=st ; i<=end; i++){
        nums[i] = temp[k++];
     }
}

void mergeSort(vector<int> &nums, int st, int end){

    if(st>=end)
        return;

    int mid =(st+end)/2;

    mergeSort(nums, st, mid);
    mergeSort(nums, mid+1, end);

    if(nums[mid]>nums[mid+1])
        merge(nums, st, mid, end);
}

int main()
{
    vector<int> nums = {6,4,7,3,6,83,9};
    mergeSort(nums, 0, nums.size()-1);
    for(int i =0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}