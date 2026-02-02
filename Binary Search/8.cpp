/*
### Aggressive Cows — Approach (Points) 🐄

* Sort the `stalls` array to process positions in increasing order.
* The problem is to **maximize the minimum distance** between any two cows.
* Use **Binary Search on Answer** 

**Search Space**

* `s = 1` → minimum possible distance  OR min distance between any two stall.
* `e = stalls[n-1] - stalls[0]` → maximum possible distance OR max distance between any two stall.

**Binary Search Steps**

* Find `mid` as the candidate minimum distance.
* Check if it is possible to place `k` cows with at least `mid` distance.

**Feasibility Check (`isPossible`)**

* Place the first cow at the first stall.
* Traverse remaining stalls:

  * Place a cow if distance from last placed cow ≥ `mid`.
  * Increase cow count.
* If `cowCount == k`, return `true`.
* If all stalls are checked and cows < `k`, return `false`.

**Decision**

* If placement is possible → move right (`s = mid + 1`) to increase distance.
* If placement is not possible → move left (`e = mid - 1`) to reduce distance.

**Result**

* After binary search, `e` stores the **maximum possible minimum distance** between cows.

**Time Complexity**

* Sorting: `O(n log n)`
* Binary search with feasibility check: `O(n log(range))`

*/

bool isPossible(vector<int> &stalls, int n, int k, int minDistance){
    int cowCount = 1;
    int lastPos = 0;

    for(int i=1;i<n;i++){
        if(stalls[i] - stalls[lastPos] >= minDistance){
            cowCount++;
            if(cowCount == k){
                return true;
            }

            lastPos = i;
        }
    }

    return false;
}

int binarySearch(vector<int> &stalls, int n, int k, int s, int e){
    while(s <= e){
        int mid = (s + e) >> 1;

        if(isPossible(stalls, n, k, mid)){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }

    return e;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();

    int s = 1;
    int e = stalls[n-1] - stalls[0];

    return binarySearch(stalls, n, k, s, e);
}
