class Solution {
private :
    bool isPossible(int m, int k, vector<int>& bloomDay, int mid)
    {
        int flowers = m*k ;
        int boq = 0 ;
        int temp = 0 ;
        for(auto ele : bloomDay)
        {
            if(ele <= mid)
                temp++ ;
            else 
                temp = 0 ;
            
            if(temp == k)
            {
                boq++ ;
                temp = 0 ;
            }
        }
        
        // cout<<mid<<" "<<boq<<endl ;
        return (boq >= m) ;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int low, high, mid ;
        low = 1 ;
        high = 1 ;
        
        for(auto ele : bloomDay)
        {
            high = max(ele, high) ;
        }
        
        int res = -1 ;
        // sort(bloomDay.begin(), bloomDay.end()) ;
        while(low <= high)
        {
            mid = (low+high)/2 ;
            if(isPossible(m, k, bloomDay, mid))
            {
                res = mid ;
                high = mid-1 ;
            }
            
            else 
                low = mid+1 ;
        }
        
        return res ;
    }
};