#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target){
    for(int i = 0 ; i<nums.size()-1 ; i++){
        for(int j = i+1 ; j<nums.size() ; j++){
            if (nums[j] == target-nums[i]){
                vector<int> indices;
                indices.push_back(i);
                indices.push_back(j);
                return indices;
            }
        }
    }
}

vector<int> pairSum2(vector<int> nums, int target){
    for(int i = 0 ; i<nums.size()-1 ; i++){
        int st = i+1;
        int end =nums.size()-1;
        while(st<=end){
            int mid  = (st+end)/2;
            if (nums[mid] == target-nums[i]){
                vector<int> indices ;
                indices.push_back(i);
                indices.push_back(mid);
                return indices;
            }
            else if(nums[mid]>target-nums[i])
                end = mid-1;
            else 
                st = mid+1;
        }
    }
}

vector<int> pairSum3(vector<int>nums , int target){
    int st = 0;
    int end = nums.size()-1;
    while(st<end){
        int currSum=nums[st]+nums[end];
        if(currSum==target){
            vector<int> indices;
            indices.push_back(st);
            indices.push_back(end);
            return indices;
        }
        else if(currSum>target)
            end--;
        else 
        st++;
    }
}

int main()
{
    vector<int> nums = {2,7,11,17};
    int target = 18;
    vector <int> indices = pairSum3(nums, target);
    cout<<indices[0]<<endl;
    cout<<indices[1];
    return 0;
}