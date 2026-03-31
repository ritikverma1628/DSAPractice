#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void printTriplets(vector<vector<int>> triplets){
    for(int i = 0 ; i<triplets.size() ; i++){
        for(int j = 0 ; j<triplets[0].size(); j++){
            cout<<triplets[i][j]<<" ";
        }
        cout<<endl;
    }
}

// ---------------------------------------------------------------------------------------------------

vector<vector<int>> threeSum(vector<int> &nums){
    set<vector<int>> uniqueTriplets;
    for(int i = 0 ; i<nums.size()-2; i++){
        for(int j = i+1 ; j<nums.size()-1; j++){
            for(int k = j+1 ; k<nums.size() ; k++){
                if(nums[i]+nums[j]+nums[k] ==0){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
            }
        }
    }
    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}
//-------------------------------------------------------------------------------------------------

vector<vector<int>> threeSum2(vector<int> &nums){
    set<vector<int>> uniqueTriplets;
    for(int i = 0 ; i<nums.size()-2; i++){
        set<int> s ;
        for(int j = i+1 ; j<nums.size() ; j++){
            int target = -(nums[i]+nums[j]);
            if(s.find(target)!=s.end()){
                vector<int> triplet = {nums[i], nums[j], target};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }
            s.insert(nums[j]);
        }
    }
    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

//-------------------------------------------------------------------------------------------------------

vector<vector<int>> threeSum3(vector<int> &nums){
    vector<vector<int>> triplets;
    int size = nums.size();
    if(size<3) return {};
    sort(nums.begin(), nums.end());
    for(int i = 0 ; i < size-2 ; i++){
        if(i>0 && nums[i]==nums[i-1])
            continue;
        int j = i+1;
        int k =nums.size()-1;
        while(j<k){              
            int currSum = nums[i]+nums[j]+nums[k];
            if(currSum==0){
                triplets.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
            else if(currSum>0)
                k--;
            else
                j++;
        }
    }
    return triplets;
}

int main()
{
    vector<int> nums = {-2, 0, 0, 2, 2};
    vector<vector<int>> triplets = threeSum3(nums);
    printTriplets(triplets);
    return 0;
}