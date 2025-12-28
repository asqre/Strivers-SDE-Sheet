class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        // return solve1(nums, n);
        // return solve2(nums, n);
        return solve3(nums, n);
    }

    // kadane's Algo
    static int solve3(int[] nums, int n) {
        int ans = Integer.MIN_VALUE; // stores maximum subarray sum
        int sum = 0;                 // stores current subarray sum

        for (int i = 0; i < n; i++) {
            sum += nums[i];                  // add current element to subarray
            ans = Math.max(ans, sum);        // update maximum sum

            // If current sum becomes negative, discard it
            // because adding a negative sum to any future elements
            // will only decrease the total sum
            if (sum < 0) {
                sum = 0;
            }
        }

        return ans;
    }

    // Brute force 
    static int solve2(int[] nums, int n){
        int ans = Integer.MIN_VALUE;

        for(int i=0;i<n;i++){
            // find all subarray starting from ith index
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ans = Math.max(ans, sum);
            }
        }

        return ans;
    }

    static int solve1(int[] nums, int n){
        int ans = Integer.MIN_VALUE;

        for(int i=0;i<n;i++){
            // find all subarray starting from ith index
            for(int j=i;j<n;j++){
                int sum = 0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                ans = Math.max(ans, sum);
            }
        }

        return ans;
    }
}