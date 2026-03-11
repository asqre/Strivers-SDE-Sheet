/*
Time Complexity: O(NlogN) + O(N) ~ O(NlogN)
Space Complexity: O(3N)
Approach: We can sort the meetings based on their end time.
Then we can iterate through the sorted meetings and count the number of meetings that can be attended.
We can keep track of the end time of the last attended meeting and compare it with the start
time of the current meeting. If the start time of the current meeting is greater than the end time of the last attended meeting, 
then we can attend the current meeting and update the end time of the last attended meeting.
*/
bool comp(vector<int> &a, vector<int> &b){
    return a[1] <= b[1];
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<vector<int>> meetings;   
    int n = start.size();

    for(int i=0;i<n;i++){
        meetings.push_back({start[i], end[i]});
    }

    sort(meetings.begin(), meetings.end(), comp);

    int no_of_meetings = 0;
    int prev_end_time = 0;

    for(int i=0;i<n;i++){
        int curr_start_time = meetings[i][0];

        if(curr_start_time > prev_end_time){
            no_of_meetings++;
            prev_end_time = meetings[i][1];
        }
    }

    return no_of_meetings;
}