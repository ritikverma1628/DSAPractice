#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int > nums , int i, int target){
    if(i==nums.size())
        return -1;
    if(nums[i]==target)
        return i ;
    return firstOccurence(nums, i+1, target);

}

int main()
{
    vector<int> nums = {2,3,4,2,6,5,5,5,7};
    cout<<firstOccurence(nums, 0, 2);
    return 0;
}