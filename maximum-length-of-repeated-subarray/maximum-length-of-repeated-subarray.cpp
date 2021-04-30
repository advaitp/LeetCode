class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int m, n ;
        m = nums1.size(), n = nums2.size() ;
        vector<vector<int>> T (m+1,vector<int>(n+1, 0)) ;  
               
        int res = 0 ;
        for(int i = 0 ; i <= nums1.size() ; i++)
        {
            for(int j = 0 ; j <= nums2.size() ; j++)
            {
                if(i == 0 || j == 0) T[i][j] = 0 ;
                else if(nums1[i-1] == nums2[j-1])
                {
                    T[i][j] = T[i-1][j-1]+1 ;
                    res = max(res, T[i][j]) ;
                }
                    
                else 
                    T[i][j] = 0 ;
            }
        }
        
        return res ;
    }
};