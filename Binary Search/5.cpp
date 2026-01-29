/*
### ✅ **Approach: Median of Two Sorted Arrays (Binary Search – Optimal)**

1. **Ensure binary search on smaller array**

   * If `nums1` is larger than `nums2`, swap them.

2. **Apply binary search on nums1**

   * Search space: `0` to `n1`.

3. **Create partitions**

   * `p1` → partition in `nums1`
   * `p2` → partition in `nums2`
   * Ensure left half has `(n1 + n2 + 1) / 2` elements.

4. **Identify boundary elements**

   * Left side max values: `x1`, `x2`
   * Right side min values: `x3`, `x4`
   * Use `INT_MIN` and `INT_MAX` for out-of-bound cases.

5. **Check valid partition**

   * Condition:
     `x1 ≤ x4` **and** `x2 ≤ x3`

6. **Calculate median**

   * If total length is even →
     `(max(x1, x2) + min(x3, x4)) / 2`
   * If odd →
     `max(x1, x2)`

7. **Adjust binary search**

   * If `x1 > x4` → move left
   * Else → move right

---

### ⏱ Complexity

* **Time:** `O(log(min(n1, n2)))`
* **Space:** `O(1)`

Clean, optimal, and interview-ready 🚀

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Brute Force
        // return solve1(nums1, nums2, n1, n2);

        // optimal Solution
        return solve2(nums1, nums2, n1, n2);
    }

private:
    double solve2(vector<int>& nums1, vector<int>& nums2, int n1, int n2){
        if(n1 > n2){
            return solve2(nums2, nums1, n2, n1);
        }

        int s = 0;
        int e = n1;

        while(s <= e){
            int p1 = s + (e - s)/2;
            int p2 = (n1 + n2 + 1)/2 - p1;

            // left half
            int x1 = (p1 == 0) ? INT_MIN : nums1[p1 - 1];
            int x2 = (p2 == 0) ? INT_MIN : nums2[p2 - 1];

            // right half
            int x3 = (p1 == n1) ? INT_MAX : nums1[p1]; 
            int x4 = (p2 == n2) ? INT_MAX : nums2[p2];

            if(x1 <= x4 && x2 <= x3){
                if((n1 + n2) % 2 == 0){
                    return (max(x1, x2) + min(x3, x4))/2.0;
                }else{
                    return max(x1, x2);
                }
            }

            if(x1 > x4){
                e = p1 - 1;
            }else{
                s = p1 + 1;
            }
        }

        return -1;
    }

    double solve1(vector<int>& nums1, vector<int>& nums2, int n1, int n2){
        vector<int> temp;

        for(int i=0;i<n1;i++){
            temp.push_back(nums1[i]);
        }

        for(int i=0;i<n2;i++){
            temp.push_back(nums2[i]);
        }

        sort(temp.begin(), temp.end());

        bool isEven = (n1 + n2) % 2 == 0;

        int n = n1 + n2;
        double median = 0.0;

        if(isEven){
            median = (temp[n/2 - 1] + temp[n/2])/2.0;
        }else{
            median = (double)temp[n/2];
        }

        return median;
    }
};