#include<iostream>
#include<vector>
using namespace std;

//ek array me jisme 1 se n tak number the to usme ek number ko hataya aur uski jagah 1 se n tak ka koi number firse daal diya , to ab vo pair return karna hai jo number remove hua hai aur jo repeat hua hai 

vector<int> setMismatch(vector<int> &nums){
    vector<int> freq(nums.size()+1, 0);
    vector<int> ans(2);
    for(int num: nums){
        freq[num]++;
    }
    for(int i = 1 ; i<freq.size() ; i++){
        if(freq[i]==2)
            ans[0] = i;
        else if (freq[i]==0)
            ans[1] = i;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,3,4,1,5,6,7,5,9,10};
    vector<int> ans = setMismatch(nums);    
    cout<<ans[0]<<endl;
    cout<<ans[1];
    return 0;
}