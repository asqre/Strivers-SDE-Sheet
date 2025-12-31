class Solution {
    public int uniquePaths(int m, int n) {
        // return solve1(m, n, 0, 0);

        // int[][] dp = new int[m][n];
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         dp[i][j] = -1;
        //     }
        // }
        // return solve2(m, n, 0, 0, dp);

        return solve3(m, n);
    }

    static int solve3(int m, int n){
        int[][] dp = new int[m][n];

        // Base case:
        // There is only 1 way to reach any cell in
        // first row or first column
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int i=0;i<n;i++){
            dp[0][i] = 1;
        }

        // Fill the dp table
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] +dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }

    static int solve2(int m, int n, int i, int j, int[][] dp){
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(i < 0 || i >= m || j < 0 || j>= n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solve1(m, n, i + 1, j);
        int right = solve1(m, n, i, j + 1);

        dp[i][j] = right + down;
        return dp[i][j];
    }

    static int solve1(int m, int n, int i, int j){
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(i < 0 || i >= m || j < 0 || j>= n){
            return 0;
        }

        int down = solve1(m, n, i + 1, j);
        int right = solve1(m, n, i, j + 1);

        return right + down;
    }
}