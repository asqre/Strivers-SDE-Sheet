public class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        // return solve1(prices, n);
        return solve2(prices, n);
    }

    /* Approach:- sell the product from ith day and check the profit with min of (0 to i-1th day)
    OR
    Approach:
    Traverse the array and keep track of the minimum price seen so far.
    For each day, assume we sell on that day and calculate profit using
    the minimum price from previous days.
    Update the maximum profit accordingly.
    */
    static int solve2(int[] prices, int n){
        int mini = prices[0];
        int maxProfit = 0;

        for(int i=0;i<n;i++){
            int sellStock = prices[i];
            int profit = sellStock - mini;
            maxProfit = Math.max(maxProfit, profit);
            mini = Math.min(mini, prices[i]);
        }

        return maxProfit;
    }

    static int solve1(int[] prices, int n){
        int ans = 0;

        for(int i=0;i<n;i++){
            int buyStock = prices[i];

            for(int j=i+1;j<n;j++){
                int sellStock = prices[j];
                int profit = sellStock - buyStock;

                ans = Math.max(profit, ans);
            }
        }

        return ans;
    }
} {
    
}
