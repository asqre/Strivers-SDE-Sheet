class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        // return solve1(nums, n);
        return solve2(nums, n);
    }

    // Boyre moore majority vote algorithm
    static int solve2(int[] nums, int n){
        // Step 1: Find potential majority element
        int majorityElement = 0;
        int cnt = 0; // cnt of majority element

        for(int num : nums){
            if(num == majorityElement){
                cnt++;
            }else if(cnt == 0){
                majorityElement = num;
                cnt++;
            }else if(num != majorityElement){
                cnt--;
            }
        }

        // Step 2: Verify majority element
        cnt = 0;
        for(int num : nums){
            if(num == majorityElement){
                cnt++;
            }
        }

        if(cnt > n/2){
            return majorityElement;
        }

        // No majority element exists
        return -1;
    }

    // T.c= O(n^2)
    static int solve1(int[] nums, int n){
        int times = n/2;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[i] == nums[j]){
                    cnt++;
                }

                if(cnt > times){
                    return nums[i];
                }
            }
        }

        return 0;
    }
}