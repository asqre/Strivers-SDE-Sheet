/*
Method-1: Brute Force

Traverse the matrix and store all elements in a single array.

Sort the array.

Return the element at index (m * n) / 2.

Time Complexity: O((m*n) log(m*n))
Space Complexity: O(m*n)

Method-2: Optimal (Binary Search on Answer)

Since each row of the matrix is sorted, the minimum element is the first element of rows and the maximum element is the last element of rows.

Set:

low = minimum of first elements

high = maximum of last elements

Calculate medianIndex = (m * n) / 2.

Apply binary search between low and high:

Find mid

Count how many elements in the matrix are ≤ mid using upper_bound in each row.

If count ≤ medianIndex, move right → low = mid + 1

Else move left → high = mid - 1

When binary search ends, low will be the median.

Time Complexity: O(m * log n * log(max − min))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

int solve1(vector<vector<int>> &matrix, int m, int n){
    vector<int> nums;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            nums.push_back(matrix[i][j]);
        }
    }

    sort(nums.begin(), nums.end());

    return nums[(n*m)/2];
}

int countSmallerThanMid(vector<vector<int>> &matrix, int m, int n, int x){
    int count = 0;

    for(int i=0;i<m;i++){
        auto it = upper_bound(matrix[i].begin(), matrix[i].end(), x);
        int ind = it - matrix[i].begin();
        count += ind;
    }

    return count;
}

int solve2(vector<vector<int>> &matrix, int m, int n){
    int low = INT_MAX;
    int high = INT_MIN;

    for(int i=0;i<m;i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n-1]);
    }

    int medianIndex = (m * n)/2;

    while(low <= high){
        int mid = low + (high - low)/2;

        int cnt = countSmallerThanMid(matrix, m, n, mid);

        if(cnt <= medianIndex){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return low;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();

    // Brute Force
    // return solve1(matrix, m, n);

    // Optimal(Binary Search)
    return solve2(matrix, m, n);
}
