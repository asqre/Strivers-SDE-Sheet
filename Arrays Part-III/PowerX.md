# 📘 Power Function (`xⁿ`) – Fast Exponentiation

## ⚠️ IMPORTANT POINTS (READ FIRST)


## 📝 Interview One-Liner

> “Since `n` can be −2³¹, taking `abs(n)` overflows an int, so I convert `n` to long first. Then I apply fast exponentiation, using the fact that for odd `n`, `(n−1)/2` equals `n/2` in integer division.”

---


### 1️⃣ Handling Integer Overflow (`n = −2³¹`)

* The minimum value of `int` is:

  ```
  n = −2³¹
  ```
* Taking `abs(n)` causes **overflow**:

  ```
  abs(−2³¹) = 2³¹  ❌ (out of int range)
  ```
* **Solution**:

  * Convert `n` to `long` **before** any operation
  * If `n` is negative, compute:

    ```
    x⁻ⁿ = 1 / xⁿ
    ```

---

### 2️⃣ Odd Power Optimization

* For **odd `n`**:

  ```
  n = 2k + 1
  ```
* Integer division property:

  ```
  (n - 1) / 2 == n / 2
  ```
* This allows us to safely compute:

  ```
  xⁿ = x × (x^(n/2))²
  ```

---

## 🧠 Approach Used

We use **Fast Exponentiation (Binary Exponentiation)** to reduce time complexity.

### Key Ideas:

* Divide power by 2 at each step
* Square the result
* Multiply by `x` only when `n` is odd

---

## 🧾 Code Implementation

```java
class Solution {
    public double myPow(double x, int n) {
        // return solve1(x, n);
        return solve2(x, (long)n);
    }

    static double solve2(double x, long n){
        double temp = power(x, n);
        if(n < 0){
            temp = 1.0/power(x, -n);
        }

        return temp;
    }

    static double power(double x, long n){
        if(n == 0){
            return 1.0;
        }

        double ans = power(x, n/2);
        ans *= ans;

        if(n % 2 != 0){
            return x * ans;
        }

        return ans;
    }

    static double solve1(double x, int n){
        return Math.pow(x, n);
    }
}
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(log n)` (recursion stack)

---


