/* Three approaches:
1. Using nested for-loops (brute force).
2. Using a hash map by storing (value, index).
3. Sorting the array and using the two-pointer technique
   (left = 0, right = n - 1).
*/

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        // int[] solve1 = solve1(nums, target, n);
        // return solve1;

        int[] solve2 = solve1(nums, target, n);
        return solve2;
    }

    static int[] solve2(int[] nums, int target, int n) {
        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }

        Arrays.sort(arr);

        int left = 0, right = n - 1;

        int[] ans = { -1, -1 };

        while (left < right) {
            int sum = arr[left][0] + arr[right][0];

            if (sum == target) {
                ans[0] = arr[left][1];
                ans[1] = arr[right][1];
                return ans;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }

        return ans;
    }

    static int[] solve1(int[] nums, int target, int n) {
        int[] ans = new int[2];

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
                ;
            }
        }

        return ans;
    }
}