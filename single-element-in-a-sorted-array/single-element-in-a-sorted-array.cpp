class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        // log n complexity
        
        int l, r ;
        l = 0 , r = nums.size()-1 ;
        int mid ;
        
        while(l <= r)
        {
            mid = (l+r)/2 ;
            if (l == r) 
            {
                return nums[l];
            }
            
            if(mid % 2 == 0 && mid < nums.size()-1)
            {
                if(nums[mid] == nums[mid+1])
                    l = mid+2 ;
                
                else
                    r = mid ;
            }
            
            if(mid % 2 != 0)
            {
                if(nums[mid] == nums[mid-1])
                    l = mid+1 ;
                
                else
                    r = mid-1 ;
            }
        }
        
        return nums[l] ;
    }
    
};