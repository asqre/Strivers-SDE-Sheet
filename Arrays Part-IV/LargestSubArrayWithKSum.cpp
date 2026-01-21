/*
Method - 1 (Brute)
a. go to each element and find subArray whose sum equal to k.
b. update the length of such SubArray to max.

Method - 2 (Better)
a. Assume, we have sum of array to ith index is equal to x, also, there is subArray exist inside that array whose sum is k, then sum of remaining would be x - k;
b. store the sum till ith index in map with i value. (i.e, till index val, sum is key)

Method - 3(Optimal)
✅ Approach (Sliding Window)
1. Initialize two pointers left and right at 0
2. Maintain a variable sum to store current window sum
3. Expand the window by moving right and adding a[right] to sum
4. If sum > k, shrink the window by moving left and subtracting a[left]
5. When sum == k, update the maximum subarray length
6. Continue until right reaches the end of the array
7. Return the maximum length found

*/

int longestSubarrayWithSumK(vector<int> a, long long k) {
    return solve1(a, k);
    return solve2(a, k);
    return solve3(a, k);
}

// Optimal: T.C = O(n)
int solve3(vector<int> a, long long k) {
    // Write your code here
    int left = 0;
    int right = 0;
    int n = a.size();

    int ans = 0;
    long long sum = 0;

    while(right < n){
        sum += a[right];

        while(sum > k && left <= right){
            sum -= a[left];
            left++;
        }

        if(sum == k){
            ans = max(ans, right - left + 1);
        }

            
        right++;
    }

    return ans;
}

// Better T.C = O(n), S.C= O(n)
int solve2(vector<int> a, long long k){
    int n = a.size();
    unordered_map<int, int> m;
    int ans = 0;

    long long sum = 0;

    for(int i = 0;i < n;i++){
        sum += a[i];

        long long diff = sum - k;

        if(diff == 0){
            ans = i + 1;
        }

        if(m.find(diff) != m.end()){
            ans = max(ans, i - m[diff]);
        }

        if (m.find(sum) == m.end()) {
            m[sum] = i;
        }
    }

    return ans;
}

// Brute T.C = O(n^2) 
int solve1(vector<int> a, long long k) {
    int ans = 0;
    int n = a.size();

    for(int i=0;i<n;i++){
        ans = max(ans, maxSizeOfK(a, k, n, i));
    }

    return ans;	
}

int maxSizeOfK(vector<int> a, long long k, int n, int i){
    int ans = 0;
    long long sum = 0;

    for(int j=i;j<n;j++){
        sum += a[j];
        if(sum == k){
            ans = max(ans, j - i + 1); 
        }else if(sum > k){
            break;
        }
    }

    return ans;
}

