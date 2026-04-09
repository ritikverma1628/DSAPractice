#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &nums, int st, int end, int key){
    if(st==end){
        if(nums[st]==key)
            return st;
        else
            return -1;
    }

    int mid = (st+end)/2;
    int idx1= binarySearch(nums, 0, mid, key);
    int idx2 = binarySearch(nums, mid+1, end, key);

    if(idx1 ==-1 && idx2==-1)
        return -1;
    else
        return idx1==-1?idx2:idx1;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    cout<<binarySearch(nums, 0, nums.size()-1, -1);
    return 0;
}