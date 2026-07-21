class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0],newInterval[1]});
        sort(intervals.begin(),intervals.end());\
        vector<vector<int>>ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.size();
        for(int i=1; i<n; i++){
            int newStart = intervals[i][0];
            int newEnd = intervals[i][1];

            if(end >= newStart){
                end = max(end,newEnd);
            }else{
                ans.push_back({start,end});
                start = newStart;
                end = newEnd;
            }
        }
        ans.push_back({start,end});
        return ans;
        
    }
};