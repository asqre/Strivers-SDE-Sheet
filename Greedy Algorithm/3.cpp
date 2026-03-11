#include <bits/stdc++.h>

bool comp(vector<int> &a, vector<int> &b){
    return a[2] > b[2];
}

vector<int> solve1(vector<vector<int>> &jobs, int n){
    sort(jobs.begin(), jobs.end(), comp);

    int maxDeadlines = 0;
    for(auto v : jobs){
        maxDeadlines = max(maxDeadlines, v[1]);
    }

    vector<bool> availableSlots(maxDeadlines, false);

    int noOfJobDone = 0;
    int profit = 0;

    for(int i = 0; i < n; i++){
        int deadline = jobs[i][1];

        for(int j = deadline - 1; j >= 0; j--){
            if(!availableSlots[j]){
                noOfJobDone++;
                profit += jobs[i][2];
                availableSlots[j] = true;
                break;
            }
        }
    }

    return {noOfJobDone, profit};
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();

    /*
    Greedy Approach
    T.C = O(NlogN) + O(N*M) ~ O(NlogN) where M is the maximum deadline
    S.C = O(N) for sorting + O(M) for availableSlots ~ O(N + M)
    We can sort the jobs based on their profit in descending order. Then we can iterate through the sorted jobs and for each job,
    
    */
    return solve1(jobs, n);
}