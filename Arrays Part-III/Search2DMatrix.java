class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int r = matrix.length;
        int c = matrix[0].length;

        //
        // return solve1(matrix, target, r, c);
        
        // return solve2(matrix, target, r, c);
        
        // return solve3(matrix, target, r, c);
        
        // Approach 4: Identify Possible Row + Binary Search
        return solve4(matrix, target, r, c);

        // Approach 5: Binary Search on Entire Matrix (BEST)
        // return solve5(matrix, target, r, c);
    }

    // T.C = O(log(m*n))
    static boolean solve5(int[][] matrix, int target, int r, int c){
        int s = 0;
        int e = r * c - 1;

        while(s <= e){
            int m = s + (e - s) / 2;

            int row = m / c;
            int col = m % c;

            int val = matrix[row][col];
            if(val == target) return true;

            if(val > target){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }

        return false;
    }

    // T.C=O(n) + O(longm)
    static boolean solve4(int[][] matrix, int target, int r, int c){
        for(int i=0;i<r;i++){
            if(matrix[i][0] <= target && target <= matrix[i][c-1]){
                return hasTarget(matrix[i], target, c);
            }
        }

        return false;
    }

    // T.C = O(m*n) + O(log(m*n))
    static boolean solve3(int[][] matrix, int target, int r, int c){
        int[] temp = new int[r * c];

        int k = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                temp[k++] = matrix[i][j];
            }
        }

        return hasTarget(temp, target, r * c);
    }

    // 1. Given that each row is sorted and the first element of each row is greater 
    //    than the last element of the previous row, we can efficiently apply binary search.
    // 2. We perform binary search on each row, resulting in a time complexity of O(m log n).
    static boolean solve2(int[][] matrix, int target, int r, int c){
        boolean ans = false;

        for(int i=0;i<r;i++){
            ans = hasTarget(matrix[i], target, c);
            if(ans) return ans;
        }

        return ans;
    }

    static boolean hasTarget(int[] arr, int target, int n){
        int s = 0, e = n-1;

        while(s <= e){
            int m = s + (e - s)/2;

            if(arr[m] == target) return true;

            if(arr[m] > target){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }

        return false;
    }

    static boolean solve1(int[][] matrix, int target, int r, int c){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }

        return false;
    }
}