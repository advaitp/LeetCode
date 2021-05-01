class Solution {
private :
    static bool comp(const pair<int,int> &a, const pair<int,int> &b)
    {
        if(a.first == b.first)
            return (a.second < b.second) ;
        return (a.first < b.first) ;
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<pair<int,int>> mp ;
        vector<int> res ; 
        
        for(int j = 0 ; j < arr.size() ; j++)
        {
            int curr_dist = abs(arr[j]-x) ;
            mp.push_back({curr_dist, j}) ;
        }
        
        sort(mp.begin(), mp.end(), comp) ;
        
        for(int j = 0 ; j < k ; j++)
        {
            res.push_back(arr[mp[j].second]) ;
        }
        
        sort(res.begin(), res.end()) ;        
        return res ;
    }
};