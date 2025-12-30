class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        // return solve1(nums, n);
        // return solve2(nums, n);
        return solve3(nums, n);
    }

    // Hare & Tortoise algo - using slow and fast pointer
    int solve3(int[] nums, int n){
        int slow = 0;
        int fast = 0;

        // Step 1: Detect cycle
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Step 2: Find duplicate
        slow = 0;

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; //fast
    }

    // This approach not work, because array not getting modified.
    // Traverse the array.
    // Treat the absolute value of each element as an index.
    // If the value at that index is already negative, it means the element is repeated.
    // Otherwise, mark it as visited by making it negative.
    static int solve2(int[] nums, int n){
        for(int i=0;i<n;i++){
            int index = Math.abs(nums[i]);

            // If already -ve, duplicate found
            if(nums[index] < 0){
                return index;
            }

            // Mark as negative
            nums[index] = -nums[index];
        }

        return -1; // no duplicacy found
    }
    
    // Brute force approach
    // For each element, compare it with the remaining elements (O(n²)).
    static int solve1(int[] nums, int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && nums[j] == nums[i]){
                    return nums[i];
                }
            }
        }

        return 0;
    }
}