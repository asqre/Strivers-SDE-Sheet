class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // solve1(matrix, n);
        solve2(matrix, n);
    }

    /*
    Approach
    1. Transpose the matrix -> converting rows into column.
    2. Reverse each row
    */
    static void solve2(int[][] matrix, int n){
        // Step 1: Transpose
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swapMatrix(matrix, i, j);
            }
        }

        // Step 2: Reverse each row
        for(int i=0;i<n;i++){
            reverse(matrix[i], n);
        }
    }

    static void reverse(int[] row, int n){
        int left = 0;
        int right = n-1;

        while(left<=right){
            swapArray(row, left, right);
            left++;
            right--;
        }
    }

    static void swapArray(int[] row, int left, int right){
        int temp = row[left];
        row[left] = row[right];
        row[right] = temp;
    }


    static void swapMatrix(int[][] matrix, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }

    // Taking extra space
    static void solve1(int[][] matrix, int n) {
        int[][] ans = new int[n][n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = matrix[n-1-j][i];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
}