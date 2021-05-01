class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        auto compStart = [&](const int i, const int j){ return intervals[i][0] > intervals[j][0]; };
        auto compEnd = [&](const int i, const int j){ return intervals[i][1] > intervals[j][1]; };
        priority_queue<int, vector<int>, decltype(compStart)> sQ(compStart); 
        priority_queue<int, vector<int>, decltype(compEnd)> eQ(compEnd); 
        vector<int> res(intervals.size(), -1);
        
        for(int i = 0 ; i < intervals.size() ; i++)
        {
            sQ.push(i) ;
            eQ.push(i) ;
        }
        
        while(!sQ.empty() && !eQ.empty())
        {
            int end = eQ.top() ;
            eQ.pop() ;
            while(!sQ.empty() && intervals[sQ.top()][0] < intervals[end][1])
            {
                sQ.pop() ;
            }
                
            
            if(!sQ.empty())
            {
                res[end] = sQ.top() ;
            }
        }
        
        return res ;
    }
};