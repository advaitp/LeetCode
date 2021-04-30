class Solution {
public:

int lengthOfLIS(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> tail; 
    tail.push_back(nums[0]);
    for(int i=1;i < n ;i++){
        if(nums[i] > tail.back() )
            tail.push_back(nums[i]);
        else{
            int idx =  lower_bound(tail.begin() , tail.end() , nums[i] ) - tail.begin();
            tail[idx] = nums[i];
        }
    }
    return tail.size();
}
};