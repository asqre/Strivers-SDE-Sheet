/*
## **Method 1: Using Min Heap**

**Approach**

* Insert all elements of both arrays into a **min heap**.
* Pop elements from the heap **k times**.
* The **kth popped element** is the answer.

**Why it works**

* Min heap always keeps the smallest element at the top.

**Time Complexity**

* Building heap: `O((n + m) log(n + m))`
* Extracting k elements: `O(k log(n + m))`

**Space Complexity**

* `O(n + m)`

---

## **Method 2: Using Temporary Vector + Sorting**

**Approach**

* Create a temporary vector.
* Push all elements from both arrays into it.
* Sort the combined vector.
* Return the element at index `k - 1`.

**Why it works**

* Sorting puts elements in increasing order, making kth element direct.

**Time Complexity**

* `O((n + m) log(n + m))`

**Space Complexity**

* `O(n + m)`

---

## **Method 3: Using Two Pointers**

**Approach**

* Use two pointers `i` and `j` for both sorted arrays.
* Compare `arr1[i]` and `arr2[j]`, move the pointer with smaller value.
* Maintain a counter for how many elements have been processed.
* When counter reaches `k`, return the current element.

**Why it works**

* Similar to the merge step of merge sort, but stops early.

**Time Complexity**

* `O(k)`

**Space Complexity**

* `O(1)`

---

## **Method 4: Binary Search Using Partition (Optimal Approach)**

*(Used in your `solve2` function)*

### **Core Idea**

* Divide the combined sorted elements into **two parts**:

  * Left part contains `k` elements
  * Right part contains `n + m - k` elements
* All elements in **left part ≤ right part**

---

### **Steps**

**a. Partition logic**

* Assume we take `p1` elements from `nums1`
* Remaining `p2 = k - p1` elements come from `nums2`

**b. Binary search**

* Apply binary search **only on the smaller array** to minimize time
* Search range:

  * `low = max(0, k - n2)`
  * `high = min(k, n1)`

**c. Validate partition**

* Let:

  * `x1 = nums1[p1 - 1]` (left max of nums1)
  * `x2 = nums2[p2 - 1]` (left max of nums2)
  * `y1 = nums1[p1]` (right min of nums1)
  * `y2 = nums2[p2]` (right min of nums2)

* Correct partition when:

  ```
  x1 <= y2 AND x2 <= y1
  ```

* Answer is:

  ```
  max(x1, x2)
  ```

**d. Adjust binary search**

* If `x1 > y2` → move left (`high = p1 - 1`)
* Else → move right (`low = p1 + 1`)

---

### **Why this works**

* Ensures exactly `k` smallest elements are on the left
* Binary search guarantees optimal performance

**Time Complexity**

* `O(log(min(n, m)))`

**Space Complexity**

* `O(1)`

---
*/

#include <bits/stdc++.h>

int solve1(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    vector<int> nums;

    for(auto num: arr1){
        nums.push_back(num);
    }

    for(auto num: arr2){
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    return nums[k-1];
}


int solve2(vector<int> &nums1, vector<int>& nums2, int n1, int n2, int k){
    if(n1 > n2){
        return solve2(nums2, nums1, n2, n1, k);
    }

    int low = max(0, k - n2); // minimum Element take from array 1.
    int high = min(k, n1); // maximum element take from array 1.

    while(low <= high){
        int p1 = (low + high) >> 1;
        int p2 = k - p1;

        int x1 = (p1 == 0) ? INT_MIN : nums1[p1-1]; // p1==0 means, we are not taking any element from array1
        int x2 = (p2 == 0) ? INT_MIN : nums2[p2-1];
        int y1 = (p1 == n1) ? INT_MAX : nums1[p1];
        int y2 = (p2 == n2) ? INT_MAX : nums2[p2];

        if(x1 <= y2 && x2 <= y1){
            return max(x1, x2);
        }
        
        if(x1 > y2){
            high = p1 - 1;
        }else{
            low = p1 + 1;
        }
    }

    return -1;
}

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here

    // return solve1(arr1, arr2, n, m, k);
    return solve2(arr1, arr2, n, m, k);

}