/*
### Approach (Prefix XOR + HashMap)

1. Maintain `xr` as prefix XOR till index `i`.
2. If a subarray ending at `i` has XOR `x`, then:
   [
   k \oplus x = xr \Rightarrow k = xr \oplus x
   ]
3. If `(xr ⊕ x)` exists as a prefix XOR earlier, a valid subarray exists.
4. Store prefix XORs in a hash map with their counts.
5. For each index:

   * Update `xr`
   * Add `mp[xr ⊕ x]` to answer (if exists)
   * Increment `mp[xr]`
6. Initialize `mp[0] = 1` to handle subarrays starting from index `0`.
*/

#include <bits/stdc++.h>

int solve1(vector<int> &arr, int x, int n){
    int count = 0;

    for(int i=0;i<n;i++){
        int XOR = 0;

        for(int j=i;j<n;j++){
            XOR ^= arr[j];

            if(XOR == x){
                count++;
            }
        }
    }

    return count;
}

int solve2(vector<int> &nums, int x, int n){
    int cnt = 0;
    unordered_map<int, int> m; // hashmap, that store number of subArray (as val) whose xor of element is xr (as key) 
    int xr = 0;

    m[xr] = 1; // means, there is one subArray exist whose xor is 0.

    for(int i=0;i<n;i++){
        xr ^= nums[i];
        int k = xr ^ x;
        if(m.find(k) != m.end()){
            cnt += m[k];
        } 

        m[xr]++;
    }

    return cnt;
}

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    // return solve1(arr, x, n);
    return solve2(arr, x, n);
}
