class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 

        /*
        Greedy Approach Fails because it may not always give the optimal solution. For example, if we have coins of denominations 1, 3, and 4 and we want to make an amount of 6,
         the greedy approach would choose the coin of denomination 4 first, leaving us with an amount of 2. Then it would choose two coins of denomination 1, resulting in a total of 3 coins. 
         However, the optimal solution is to choose two coins of denomination 3, resulting in a total of 2 coins.

        Therefore, we need to use a different approach, such as dynamic programming, to solve this problem optimally.
        */
        return solve1(coins, amount, n);
    }
private:
    int solve1(vector<int> &coins, int amount, int n){
        // Recursive Approach
        /*
        Time Complexity = O(n^A) where n is the number of coins and A is the amount. 
        In the worst case, we may have to explore all combinations of coins to make the amount.
        Space Complexity = O(A) for the recursion stack in the worst case when we have to explore all combinations of coins to make the amount.
        */
        // int ans = solveRec(coins, amount, n);

        /*
        Time Complexity = O(n*A) where n is the number of coins and A is the amount.
        Space Complexity = O(A) for the dp array 
        */
        // Memoization
        // vector<int> dp(amount + 1, -1);
        // int ans = solveMemo(coins, amount, n, dp);

        /*
        Time Complexity = O(n*A) where n is the number of coins and A is the amount.
        Space Complexity = O(A) for the dp array.
        */
        // Tabulation
        int ans = solveTab(coins, amount, n);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }

    int solveTab(vector<int> &coins, int A, int n){
        vector<int> dp(A + 1, 0);

        for(int j = 1; j <= A; j++){
            int minCoins = INT_MAX;

            for(int i = 0; i < n; i++){
                int res = 0;
                if(j - coins[i] >= 0){
                    res = dp[j - coins[i]];

                    if(res != INT_MAX){
                        minCoins = min(minCoins, 1 + res);
                    }
                }
            }

            dp[j] = minCoins;
        }

        

        return dp[A];
    }

    int solveMemo(vector<int> &coins, int A, int n, vector<int> &dp){
        // Base case
        if(A == 0) return 0;
        if(A < 0) return INT_MAX;

        if(dp[A] != -1){
            return dp[A];
        }

        int minCoins = INT_MAX;

        for(int i = 0; i < n; i++){
            int res = solveMemo(coins, A - coins[i], n, dp);

            if(res != INT_MAX){
                minCoins = min(minCoins, 1 + res);
            }
        }

        return dp[A] = minCoins;
    }
    
    int solveRec(vector<int> &coins, int A, int n){
        // Base case
        if(A == 0) return 0;
        if(A < 0) return INT_MAX;

        int minCoins = INT_MAX;

        for(int i = 0; i < n; i++){
            int res = solveRec(coins, A - coins[i], n);

            if(res != INT_MAX){
                minCoins = min(minCoins, 1 + res);
            }
        }

        return minCoins;
    }
};