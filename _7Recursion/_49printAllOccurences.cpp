#include<iostream>
#include<vector>
using namespace std;

void printAllOccurence(vector<int> nums, int i, int key){
    if(i == nums.size())
        return ;

    if(nums[i]==key)
    cout<<i<<" ";
    printAllOccurence(nums, i+1, key);

}

int main()
{
    vector<int> nums = {3,2,4,5,6,2,7,2,2};
    int key = 2;
    printAllOccurence(nums, 0, key);
    return 0;
}