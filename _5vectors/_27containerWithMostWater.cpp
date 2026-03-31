#include<iostream>
#include<vector>
using namespace std;

int maxWaterArea(vector<int> heights){
    int st = 0 ;
    int end = heights.size()-1;
    int maxArea = 0;
    while(st<end){
        int currArea = min(heights[st],heights[end])*(end-st);
        maxArea = max(maxArea, currArea);
        heights[st]>heights[end]?end--:st++;
    }
    return maxArea;
}

int main()
{
    vector<int> heights ={5,7,3,10,2,8};
    cout<<maxWaterArea(heights);
    return 0;
}