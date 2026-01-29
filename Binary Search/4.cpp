/*
### 🔹 Approach (Point-wise & To the Point)

1. The given array is a **rotated sorted array**.
2. First, find the **partition (rotation) index** where the order breaks
   (`nums[i] > nums[i+1]`).
3. This partition divides the array into **two sorted parts**:

   * Left part → `0` to `p-1`
   * Right part → `p` to `n-1`
4. If no partition is found (`p = 0`), the array is **not rotated**.
5. Check in which part the **target can lie**:

   * If `target >= nums[0]` and `target <= nums[p-1]`, search in left part.
   * Else, search in right part.
6. Apply **Binary Search** on the selected part.
7. If found, return the index; otherwise, return `-1`.

⏱ **Time Complexity:** `O(n) + O(log n)`
📦 **Space Complexity:** `O(1)`

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Binary Search
        return solve1(nums, target, n);
    }

private:
    int findPartitionIndex(vector<int> &nums,  int n){
        int ind = 0;

        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                ind = i+1;
                break;
            }
        }

        return ind;
    }

    int binarySearch(vector<int> &nums, int target,  int n, int s, int e){
        while(s <= e){
            int m = s + (e - s)/2;

            if(nums[m] == target){
                return m;
            }

            if(nums[m] > target){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }

        return -1;
    }

    bool isTargetInLeftPart(vector<int> &nums, int target,  int n, int p){
        if(target >= nums[0] && target <= nums[p - 1]){
            return true;
        }

        return false;
    }

    int solve1(vector<int> &nums, int target,  int n){
        int p = findPartitionIndex(nums, n);
        int ind = -1;

        // array not rotated
        if(p == 0){
            return binarySearch(nums, target, n, 0, n - 1);
        } 
        
        // target in left part
        if(isTargetInLeftPart(nums, target, n, p)){
            return binarySearch(nums, target, n, 0, p - 1);
        }

        // target in right part
        return binarySearch(nums, target, n, p, n - 1);;
    }
};