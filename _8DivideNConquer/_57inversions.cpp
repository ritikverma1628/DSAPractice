#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &nums, int st, int mid, int end){
    vector<int> temp;
    temp.reserve(end-st+1);
    
    int inversionCount = 0 ;
    int i = st;
    int j = mid+1;

    while(i<=mid && j<=end){
        if(nums[i]<nums[j])
            temp.push_back(nums[i++]);
        else{
            temp.push_back(nums[j++]);
            inversionCount+=(mid-st+1);
        }
    }

    while(i<=mid)
            temp.push_back(nums[i++]);

    while(j<=end)
            temp.push_back(nums[j++]);
   

    for(int i =0 ; i<temp.size(); i++){
        nums[i+st] = temp[i];
    }

    return inversionCount;
}

int mergeSort(vector<int> &nums, int st, int end){
    if(st>=end)
        return 0 ;

    int mid = (st+end)/2;

    int leftInversion = mergeSort(nums, st, mid);
    int rightInversion = mergeSort(nums, mid+1, end);
    int inversionCount = merge(nums, st, mid, end);

    return leftInversion+rightInversion+inversionCount;
}

int main()
{
    vector<int> nums = {5,4,3,2,1};
    cout<<mergeSort(nums, 0, nums.size());
    return 0;
}