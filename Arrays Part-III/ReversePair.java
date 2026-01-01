// find no of such pair whose left element is greater than twice of right element.
// When you see pair-based questions like Inversion Pair or Reverse Pair, 
// you should immediately think of Merge Sort.

// Points to remember 
// 1. Use Merge Sort to count reverse pairs efficiently, 
// 2. always cast to long to avoid integer overflow when checking nums[i] > 2 * nums[j]. 
// because 2 * nums[j] will do integer overflow, so take (long)2*num[j];

class Solution {
    public int reversePairs(int[] nums) {
        int n = nums.length;
        // return solve1(nums, n);
        return solve2(nums, n);
    }   

    static int solve2(int[] nums, int n){
        return mergeSortAndCount(nums, 0, n - 1);
    }

    static int countPairs(int[] a1, int n1, int[] a2, int n2){
        int pair = 0;
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(a1[i] > (long)2 * a2[j]){
                pair += (n1 - i);
                j++;
            }else{
                i++;
            }
        }

        return pair;
    }

    static int countAndMerge(int[] nums, int s, int m, int e){
        int n1 = m - s + 1;
        int n2 = e - m;

        int[] a1 = new int[n1];
        int[] a2 = new int[n2];

        for(int i=0;i<n1;i++){
            a1[i] = nums[s + i];
        }

        for(int i=0;i<n2;i++){
            a2[i] = nums[m + 1 + i];
        }

        int i = 0, j = 0, k = s;

        int pair = countPairs(a1, n1, a2, n2);
        
        while(i < n1 && j < n2){
            if(a1[i] < a2[j]){
                nums[k] = a1[i];
                i++;
            }else{
                nums[k] = a2[j];
                j++;
            }
            k++;
        }

        while(i < n1){
            nums[k] = a1[i];
            i++;
            k++;
        }

        while(j < n2){
            nums[k] = a2[j];
            j++;
            k++;
        }

        return pair;
    }

    static int mergeSortAndCount(int[] nums, int s, int e){
        if(s >= e){
            return 0;
        }

        int pair = 0;
        int mid = s + (e - s)/2;
        pair += mergeSortAndCount(nums, s, mid);
        pair += mergeSortAndCount(nums, mid + 1, e);
        pair += countAndMerge(nums, s, mid, e);

        return pair;
    }

    static int solve1(int[] nums, int n){
        int pair = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] > (long)2*nums[j]){
                    pair++;
                }
            }
        }

        return pair;
    }
}
    