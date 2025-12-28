class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        // solve1(nums, n);   // Using in-built sorting
        // solve2(nums, n);
        solve3(nums, n);     // Dutch National Flag algorithm (optimal)
    }

    // Optimal approach: Dutch National Flag Algorithm
    static void solve3(int[] nums, int n){
        /*
         We use three pointers:
         i -> boundary for 0s
         j -> current index
         k -> boundary for 2s
        */
        int i = 0;
        int j = 0;
        int k = n - 1;

        while (j <= k) {
            if (nums[j] == 0) {
                // Current element belongs to the 0s section
                swap(nums, i, j);
                i++;
                j++;
            } else if (nums[j] == 1) {
                // Element is already in the correct position
                j++;
            } else { // nums[j] == 2
                // Current element belongs to the 2s section
                swap(nums, j, k);
                k--;
            }
        }
    }

    static void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Better approach: Counting sort (two-pass solution)
    static void solve2(int[] nums, int n){
        int zeros = 0, ones = 0, twos = 0;

        // Count occurrences of 0, 1, and 2
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;
            } else if (nums[i] == 1) {
                ones++;
            } else {
                twos++;
            }
        }

        // Overwrite the array based on counts
        int index = 0;

        for (int i = 0; i < zeros; i++) nums[index++] = 0;
        for (int i = 0; i < ones; i++)  nums[index++] = 1;
        for (int i = 0; i < twos; i++)  nums[index++] = 2;
    }

    // Brute force approach: Using in-built sorting
    static void solve1(int[] nums, int n){
        Arrays.sort(nums);
    }
}
