class Solution {
private :
    int findStart(vector<int>& nums, int target)
    {
        int l, r ;
        int n = nums.size() ;
        l = 0 , r = n-1 ;
        int res = -1 ;
        int mid ;
        while(l <= r)
        {
            mid = (l+r)/2 ;
            if(nums[mid] == target)
            {
                res = mid ;
                r = mid-1 ;
            }
            
            else if(nums[mid] > target)
                r = mid-1 ;
            else 
                l = mid+1 ;
        }
        
        return res ;
    }
    
    int findEnd(vector<int>& nums, int target)
    {
        int l, r ;
        int n = nums.size() ;
        l = 0 , r = n-1 ;
        int res = -1 ;
        int mid ;
        while(l <= r)
        {
            mid = (l+r)/2 ;
            if(nums[mid] == target)
            {
                res = mid ;
                l = mid+1 ;
            }
            
            else if(nums[mid] > target)
                r = mid-1 ;
            else 
                l = mid+1 ;
        }
        
        return res ;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>res ;
        int start = findStart(nums, target) ;
        int end = findEnd(nums, target) ;
        
        return {start, end} ;
    }
};