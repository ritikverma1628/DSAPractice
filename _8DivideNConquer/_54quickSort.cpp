#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums, int st, int end){
    int i = st-1;

    for(int j=st; j<end; j++){
        if(nums[j]<nums[end]){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    i++;
    swap(nums[i], nums[end]);

    return i;
}

void quickSort(vector<int> &nums, int st, int end){
    if(st>=end)
        return;

    int pivot = partition(nums, st, end);

    quickSort(nums, st, pivot-1);
    quickSort(nums, pivot+1, end);
}

int main()
{
    vector<int> nums = {4,2,6,2,6,8,1,563,7};
    quickSort(nums, 0, nums.size()-1);
    for(int i =0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}