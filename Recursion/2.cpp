class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        /*
        Method - 1 - Bit Manipulation
        Time Complexity: O(n * 2^n + 2^n log(2^n)) -> for generating all subsets and sorting them.
        Space Complexity: O(2^n) -> for storing the sums of all subsets.
        */
        // return solve1(nums, n);

        /*
        Method -2 Recursive Approach
        Time Complexity: O(2^n) -> for generating all subsets.
        Space Complexity: O(2^n) -> for storing the sums of all subsets.
        Sorting the input array is necessary to ensure that duplicate subsets are generated in a sorted manner, which allows us to easily identify and eliminate duplicates when we insert subsets into the set.
        */
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<int> temp;
        solve2(nums, n, 0, temp, s);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
private:
    // using Bit Manipulation
    vector<vector<int>> solve1(vector<int> &nums, int n){
        set<vector<int>> st;

        for(int i=0;i<(1<<n); i++){
            vector<int> temp;

            for(int j=0;j<n;j++){
                if((i & (1 << j)) != 0){
                    temp.push_back(nums[j]);
                }
            }

            sort(temp.begin(), temp.end());

            st.insert(temp);
        }

        return {st.begin(), st.end()};
    }

    void solve2(vector<int> &nums, int n, int i, vector<int> &subset, set<vector<int>> &s){
        if(i == n){
            s.insert(subset);
            return;
        }

        // Take
        subset.push_back(nums[i]);
        solve2(nums, n, i + 1, subset, s);
        subset.pop_back(); // Backtracking step to remove the last element added to the subset

        // Not Take
        solve2(nums, n, i + 1, subset, s);
    }
};