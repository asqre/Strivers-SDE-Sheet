/*
Method-1 Better 
1. The question says consecutive, so first sort the array.
2. Sorting brings all consecutive numbers next to each other.
3. Traverse the array from left to right.
4. Skip duplicate elements, as they don’t affect consecutiveness.
5. If the difference with the previous element is 1, increase cnt.
6. If the difference is not 1, update longest and reset cnt = 1.
7. After traversal, update longest once more to include the last sequence.

method 	2- optimal using set,
1. Use a **HashSet** to store all elements of the array for **O(1)** lookup.
2. Traverse the array element by element.
3. If `num - 1` exists in the set, then `num` **cannot be the start** of a consecutive sequence → skip it.
4. If `num - 1` does **not** exist, then `num` is the **starting element** of a sequence.
5. From this starting element, keep checking `num + 1, num + 2, ...` in the set and **count the length**.
6. Update `longest` with the maximum length found.
7. Finally, return `longest`.

✔️ This avoids sorting and checks each number only once.
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

*/

class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        if(n <= 1) return n;
        return solve2(nums, n);
        // return solve1(nums, n);
    }

    // optimal-using set
    static int solve2(int[] nums, int n){
        Set<Integer> set = new HashSet<>();

        for(int i : nums){
            set.add(i);
        }

        int longest = 0;

        for (int num : set) {
            if (set.contains(num - 1)) continue;

            int cnt = 0;
            int j = 0;
            while (set.contains(num + j)) {
                cnt++;
                j++;
            }
            longest = Math.max(longest, cnt);
        }

        return longest;
    }


    // Better 
    static int solve1(int[] nums, int n){
        Arrays.sort(nums);

        int longest  = 1;
        int cnt = 1;

        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                continue;
            }else if(nums[i] - nums[i-1] == 1){
                cnt++;
            }else{
                longest = Math.max(longest, cnt);
                cnt = 1;
            }
        }

        return Math.max(longest, cnt);
    }
}