/*
### 🔹 Take / Not Take (0/1 Knapsack) – Approaches

**Idea:**
Each element has **two choices** → Take or Not Take.

---

### 1️⃣ Recursion

* Try both choices for every element.
* If `target == 0` → return true.
* If index reaches `n` → return false.

**Time:** `O(2^n)`
**Space:** `O(n)`

---

### 2️⃣ Memoization

* Same as recursion, but store results in `dp[ind][target]`.
* Avoid recomputation.
* DP size: `(n+1) × target`

**Time:** `O(n × target)`
**Space:** `O(n × target) + O(n)`

---

### 3️⃣ Tabulation

* Bottom-up DP.
* `dp[i][j]` → can we form sum `j` using elements from `i`.
* Answer at `dp[0][target]`.

**Time:** `O(n × target)`
**Space:** `O(n × target)`

---

### 4️⃣ Bit Manipulation

* Generate all subsets using bitmask.
* Check sum of each subset.

**Time:** `O(n × 2^n)`
**Space:** `O(1)`

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int totalSum = 0;

        for(auto num : nums){
            totalSum += num;
        }

        // edge case
        if(totalSum % 2 != 0) return false;

        // Recursive
        // return solve1(nums, n, 0, totalSum / 2);

        // Memoization
        // maximum sum of array is 20000. so, half is 10000
        // vector<vector<int>> dp(n+1, vector<int> (10001, -1));
        // return solve2(nums, n, 0, totalSum/2, dp);
        
        // Tabulation
        // return solve3(nums, n, totalSum/2);

        // Bit Manipulation
        return solve4(nums, n, totalSum/2);
    }

private:
    // Bit Manipulation
    bool solve4(vector<int> &nums, int n, int target){
        for(int num=0;num<(1<<n);num++){
            int sum = 0;
            for(int i=0;i<32;i++){
                if((num & (1<<i)) != 0){
                    sum += nums[i];
                }
            }

            if(sum == target){
                return true;
            }
        }

        return false;
    }

    // Tabulation,
    bool solve3(vector<int> &nums, int n, int target){
        vector<vector<bool>> dp(n+1, vector<bool> (target + 1, false));
        // base case
        for(int i=0;i<=target;i++){
            dp[n][i] = false;
        }

        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                bool take = false;
                if(j - nums[i] >= 0){
                    take = dp[i+1][j-nums[i]];
                }
                
                bool notTake = dp[i+1][j];

                dp[i][j] = (take || notTake);
            }
        }
        

        return dp[0][target];
    }

    // Memoization,
    bool solve2(vector<int> &nums, int n, int ind, int target, vector<vector<int>> &dp){
        // base case
        if(ind == n) return false;

        if(target == 0) return true;

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        // take
        bool take = false;
        if(target >= nums[ind]){
            take = solve2(nums, n, ind + 1, target - nums[ind], dp);   
        }

        // not take
        bool notTake = solve2(nums, n, ind + 1, target, dp);

        return dp[ind][target] = (take || notTake);
    }

    // Recursion, 
    bool solve1(vector<int> &nums, int n, int ind, int target){
        // base case
        if(ind == n) return false;

        if(target == 0) return true;

        // take
        bool take = solve1(nums, n, ind + 1, target - nums[ind]);

        // not take
        bool notTake = solve1(nums, n, ind + 1, target);

        return (take || notTake);
    }
};