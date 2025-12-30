## 🔗 Question Link

**Inversion Count**
👉 [https://www.naukri.com/code360/problems/count-inversions_615](https://www.naukri.com/code360/problems/count-inversions_615)

---

```
// it is given that left element is greater than right element. 
// if such exist, that means that is inversion. 

import java.util.* ;
import java.io.*; 
public class Solution {
    public static long getInversions(long arr[], int n) {
        // Write your code here.
        return solve1(arr, n);
    }

    // brute force 
    static long solve1(long[] nums, int n){
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
}

```