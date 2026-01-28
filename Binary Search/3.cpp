/*
Method 1: Brute Force

Traverse the array one by one.

Compare the current element with the next element.

If both are equal, move the pointer two steps forward (skip the duplicate pair).

If they are not equal, the current element is the non-duplicate element.

Time Complexity: O(n)

Space Complexity: O(1)

Method 2: Using XOR

Initialize a variable xor = 0.

Traverse the array and take XOR of each element with xor.

Same elements cancel each other (x ^ x = 0).

XOR with 0 keeps the number unchanged (x ^ 0 = x).

Final value of xor will be the single non-repeating element.

Time Complexity: O(n)

Space Complexity: O(1)

Method 3: Binary Search (Optimal – Sorted Array)

Since the array is sorted, use binary search.

Set s = 0, e = n - 1.

Find mid.

Check the size of the right part (mid to e):

If right part size is even:

If arr[mid] == arr[mid + 1] → single element lies on the left side.

Else → single element lies on the right side.

If right part size is odd:

If arr[mid] == arr[mid + 1] → single element lies on the right side → s = mid + 2.

Else → single element lies on the left side → e = mid - 2.

Continue until s == e.

Time Complexity: O(log n)

Space Complexity: O(1)

*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        // return solve1(nums, n);
        // return solve2(nums, n);
        return solve3(nums, n);
    }
private:
    int solve3(vector<int> &nums, int n){
        int s = 0, e = n - 1;

        while(s < e){
            int m = s + (e - s)/2;
            bool isEven = (e - m + 1) % 2 == 0;

            if(nums[m] != nums[m+1] && nums[m] != nums[m-1]){
                return  nums[m];
            }

            if(isEven){
                if(nums[m] == nums[m+1]){
                    e = m - 1;
                }else{
                    s = m + 1;
                }
            }else{
                if(nums[m] == nums[m+1]){
                    s = m + 2;
                }else{
                    e = m - 2;
                }
            }
        }

        return nums[s];
    }

    int solve2(vector<int> &nums, int n){
        int ans = 0;

        for(auto num : nums){
            ans ^= num;
        }

        return ans;
    }

    int solve1(vector<int> &nums, int n){
        int i = 0;
        while(i < n){
            if(i+1 < n && nums[i+1] == nums[i]){
                i += 2;
            }else{
                return nums[i];
            }
        }

        return 0;
    }
};