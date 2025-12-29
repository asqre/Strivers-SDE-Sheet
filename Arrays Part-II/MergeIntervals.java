/*
Approach:-
Sort intervals by start time.
Initialize start and end using the first interval.
Traverse remaining intervals:
If overlapping → extend end
Else → store previous interval and reset start, end
Push the last interval. 
*/


// java
class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;

        Arrays.sort(intervals, (a,b)-> a[0] - b[0]);

        int start = intervals[0][0];
        int end = intervals[0][1];

        List<int[]> ans = new ArrayList<>();
        
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= end){
                end = Math.max(end, intervals[i][1]);
            }else{
                int[] temp = {start, end};
                ans.add(temp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        int[] temp = {start, end};
        ans.add(temp);

        return ans.toArray(new int[ans.size()][]);
    }
}


// C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0] <= end){
                end = max(intervals[i][1], end);
            }else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};