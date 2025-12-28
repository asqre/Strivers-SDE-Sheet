/*
Approach to Find the Next Permutation

1. Find the break point (pivot):
    Traverse the array from right to left and find the first index i such that arr[i] < arr[i + 1].
    This index is called the pivot.
    OR 
    compare the consecutive element and find the pivot index such that currElement is smaller than next element. 

    If no such index exists, the array is already the largest permutation → reverse the entire array and return.

2. From the right side to the pivot index in the array, find the element which is greater than pivot element.

3. Swap pivot element with the element found in step 2.

4. Reverse the suffix:
    Reverse the subarray from index pivot + 1 to the last index.

For Example:- nums = [2, 5, 7, 6, 2] -> [2, 6, 2, 5, 7]

*/


class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;

        int pivot = -1;

        // 1. Find the pivot
        for(int i = n-2; i>=0;i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot != -1){
            int swapIndex = pivot;

            for(int j = n-1; j>=pivot; j--){
                if(nums[j] > nums[pivot]){
                    swapIndex = j;
                    break;
                }
            }

            swap(nums, pivot, swapIndex);
        }

        reverse(nums, pivot + 1, n-1);
    }

    static void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    static void reverse(int[] nums, int start, int end){
        while(start <= end){
            swap(nums, start, end);
            start++;
            end--;
        }
    }
}