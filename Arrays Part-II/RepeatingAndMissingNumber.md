# 📌 Problem
Given an array of size `n` containing numbers from `1` to `n`:
* **One number is missing**
* **One number is repeating**
---

# 🧠 Four Methods Overview (Simple Notes)

## 1️⃣ Brute Force (Count each number)

## 2️⃣ Hashing / Frequency Array - by creating a frequency array of size `n + 1`

## 3️⃣ Mathematics Method ⭐ (IMPORTANT)
Uses:
* **Sum of first n natural numbers**
* **Sum of squares of first n natural numbers**

## 4️⃣ XOR Method
* XOR all numbers from `1 to n` and array elements
* Separate missing and repeating using bit manipulation
* ⏱️ Time: `O(n)`
* 💾 Space: `O(1)`

---

# ✅ 3️⃣ Mathematics Method – Detailed Explanation

### Given:

* One number is **missing (M)**
* One number is **repeating (R)**

### Formulas:

```
Sum of first n numbers  = expectedSum = n(n+1)/2
Sum of squares of first n = expectedSumSq = n(n+1)(2n+1)/6
```

### Let:

```
S  = sum of array elements
S2 = sum of squares of array elements
```

### Then:

```
S - expectedSum = x = R - M  ---- (1)
S2 - expectedSumSq = y = R² - M² = (R - M)(R + M) ---- (2)
```

From (2) and (1):

```
R + M = y / x;

Hence, R = 
```

Now we have:

```
R - M
R + M
```

Solve:

```
R = (x + y)/2; 
M = (y - x)/2;

```


```
import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution {

    public static int[] missingAndRepeating(ArrayList<Integer> arr, int n) {
        // Write your code here

        // return solve1(arr, n);
        // return solve2(arr, n);
        // return solve3(arr, n);
        return solve4(arr, n);
    }

    // using xor 
    static int[] solve4(ArrayList<Integer> arr, int n) {

        // Step 1: XOR all array elements and numbers from 1 to n
        // The result will be (missingNumber ^ repeatingNumber)
        int xor = 0;
        for(int i = 0; i < n; i++){
            xor = xor ^ arr.get(i);   // XOR with array element
            xor = xor ^ (i + 1);      // XOR with expected number
        }

        // Step 2: Find the rightmost set bit in xor
        // This bit differentiates the missing and repeating numbers
        int bitNo = 0;
        while(true){
            if((xor & (1 << bitNo)) != 0){
                break;
            }
            bitNo++;
        }

        int zero = 0;
        int one = 0;

        // Step 3: Divide array elements into two groups based on bitNo
        // Group 1: bitNo is set
        // Group 2: bitNo is not set
        // XOR elements within each group
        for(int i = 0; i < n; i++){
            int element = arr.get(i);
            if((element & (1 << bitNo)) != 0){
                one ^= element;
            } else {
                zero ^= element;
            }
        }

        // Step 4: Divide numbers from 1 to n into the same two groups
        // and XOR them to isolate the missing and repeating numbers
        for(int i = 1; i <= n; i++){
            if((i & (1 << bitNo)) != 0){
                one ^= i;
            } else {
                zero ^= i;
            }
        }

        // Step 5: Determine which number is repeating
        // The repeating number will appear twice in the array
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr.get(i) == zero){
                cnt++;
            }
        }

        // If 'zero' appears twice, it is the repeating number
        if(cnt == 2) {
            return new int[]{one, zero}; // {missing, repeating}
        }

        // Otherwise, 'one' is the repeating number
        return new int[]{zero, one}; // {missing, repeating}
    }



    // using maths rule
    static int[] solve3(ArrayList<Integer> arr, int n){
        long sum = 0;
        long sumSq = 0;

        for(int val : arr){
            sum += val;
            sumSq += (long)val*val;
        }

        long expectedSum = (long)n*(n+1)/2;
        long expectedSumSq = (long)n*(n+1L)*(2L * n + 1L)/6L;

        long diff = sum - expectedSum;
        long diffSq = sumSq - expectedSumSq;

        long sumRm = diffSq / diff;

        int repeating = (int)(diff + sumRm)/2;
        int missing = (int)(sumRm - diff)/2;

        int[] ans = {missing, repeating};
        
        return ans;
    }

    static int[] solve2(ArrayList<Integer> arr, int n){
        int[] temp = new int[n+1];

        int M = 0, R = 0;

        for(int i=0;i<n;i++){
            int ind = arr.get(i);
            temp[ind]++;
        }

        for(int i=1;i<n+1;i++){
            if(temp[i] == 0){
                M = i;
            }else if(temp[i] == 2){
                R = i;
            }
        }

        int[] ans = {M, R};
        return ans;
    }
    

    // Brute force approach
    static int[] solve1(ArrayList<Integer> arr, int n){
        int M = 0, R = 0;

        for(int num = 1;num<=n;num++){
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(arr.get(i) == num){
                    cnt++;
                }
            }

            if(cnt == 0){
                M = num;
            }else if(cnt == 2){
                R = num;
            }
        }

        int[] ans = {M, R};
        return ans;
    }
}

```