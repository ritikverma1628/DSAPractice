#include<iostream>
#include<vector>
using namespace std;

int lastOccurence(vector<int> nums, int target, int i ){
    if(i == -1)
        return -1;
    if(nums[i] == target)
        return i ;
    return lastOccurence(nums, target, i-1);
}

int main()
{
    vector<int> nums = {2,3,4,2,6,5,5,5,7};
    int size = nums.size();
    cout<<lastOccurence(nums, 5, size-1);
    return 0;
}