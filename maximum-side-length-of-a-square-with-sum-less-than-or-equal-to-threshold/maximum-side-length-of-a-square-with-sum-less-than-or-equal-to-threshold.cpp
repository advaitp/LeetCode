class Solution {
private :
    bool squareSum(int mid, vector<vector<int>>& dp, int k)
    {
        
        for(int i=mid;i<dp.size();i++)
        {
            for(int j=mid;j<dp[0].size();j++)
            {
                int x=dp[i][j]-dp[i-mid][j]-dp[i][j-mid]+dp[i-mid][j-mid];
                if(k>=x)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        int r, c ;
        r = mat.size() ;
        c = mat[0].size() ;
        
        vector<vector<int>> psa(r+1, vector<int>(c+1, 0)) ;
        
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                psa[i][j]=mat[i-1][j-1]+psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
            }
        }
        
        int low = 1 ; 
        int high = min(r,c) ;
        int mid ;
        int len = 0; 
        while(low <= high)
        {
            mid = (low+high)/2 ;
            if(squareSum(mid, psa, threshold))
            {
                len=mid;
                low = mid+1 ;
            }
            
            else
            {
                high = mid-1 ;
            }
        }
        
        return len ;
    }
};