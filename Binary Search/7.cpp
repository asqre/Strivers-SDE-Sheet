/*
* The problem asks to **minimize the maximum pages** allocated to any student → apply **Binary Search on Answer**.
* **Search space**:

  * `s = min(arr)` → when each book is given to a different student (best case).
  * `e = sum(arr)` → when only one student gets all books (worst case).
* Use `isPossible()` to check feasibility:

  * Try to allocate books sequentially without exceeding `maximumAllocation`.
  * If students required exceed `m` or a single book exceeds `maximumAllocation`, return `false`.
* Perform binary search:

  * If allocation is possible at `mid`, try a smaller maximum (`e = mid - 1`).
  * Else, increase limit (`s = mid + 1`).
* Final answer is `s`, the **minimum feasible maximum pages**.

*/

bool isPossible(vector<int> &arr, int n, int m, int maximumAllocation){
    int totalPages = 0;
    int currentStudent = 1;

    for(int i=0;i<n;i++){
        totalPages += arr[i];

        if(totalPages > maximumAllocation){
            currentStudent++;

            if(currentStudent > m || arr[i] > maximumAllocation){
                return false;
            }

            totalPages = arr[i];
        }
    }

    return true;
}

int binarySearch(vector<int> &arr, int n, int m, int s, int e){
    while(s <= e){
        int mid = (s + e) >> 1;

        if(isPossible(arr, n, m, mid)){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    return s;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n){
        return -1;
    }
    // Write your code here.
    int totalPages = 0;
    int minPages = INT_MAX;

    for(auto pages : arr){
        totalPages += pages;
        minPages = min(minPages, pages);
    }

    // search space
    int s = minPages;
    int e = totalPages;

    return binarySearch(arr, n, m, s, e);
}