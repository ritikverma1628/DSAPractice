#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// brute---good---better--- best
//n^2
int majorityElement1(vector<int> nums){
    int count=0;
    for(int i =0 ; i< nums.size(); i++){
        for(int j = 0 ; j<nums.size(); j++){
            if(nums[i]==nums[j])
                count++;
        }
        if(count>nums.size()/2);
        return nums[i];
    }
}

//nlogn
//vector ka aadhe se zyada space to majority elements hi occupy karte hai, to n/2 posiiton pe to hamesha majority element hi ayega
int majorityElement2(vector<int> nums){
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

//n time and n space
int majorityElement3(vector<int> nums){
    unordered_map<int,int> freq;
    int n = nums.size()/2;
    for(int x: nums){
        freq[x]++;
        if(freq[x]>n)
            return x;
    }
}

//n time and 1 space
//this approach says that the count of majority element is greater than the combined count of all other elements
//so eliminating the count of other elements from majority element will result out in leaving the majority element 
int majorityElement4(vector<int> nums){
    int candidate = nums[0];
    int count = 1 ;

    for(int i = 1 ; i<nums.size(); i++){
        if(nums[i]==candidate)
            count++;
        else{
            count--;
            if(count==0){
            candidate=nums[i];
            count=1;
            }
        }    
    }
    return candidate;
}


int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<majorityElement4(nums);
    return 0;
}