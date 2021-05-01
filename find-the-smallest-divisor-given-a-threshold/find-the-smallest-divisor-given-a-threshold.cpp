class Solution {
private :
    int getSum(vector<int>& nums, int mid)
    {
        int sum = 0 ;
        for(auto ele : nums)
        {
            if(ele >= mid)
            {
                if(ele % mid == 0)
                    sum += (ele/mid) ;
                else 
                    sum += (ele/mid)+1 ;
            }
            
            else
                sum += 1 ;
            
        }
        
        return sum ;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int l, r ;
        l = 1 ;
        for(auto ele : nums)
        {
            r = max(r, ele) ;
        }
        
        int mid, res = 0 ;
        while(l <= r)
        {
            mid = (l+r)/2 ;
            if(getSum(nums, mid) > threshold)
            {
                l = mid+1 ;
            }
                
            else 
            {
                res = mid ;
                r = mid-1 ;
            }      
        }
        
        return res ;
    }
};