class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        /*
        Method 1: Using set to store unique combinations
        Time Complexity:- O(nlogn + 2^n) -> for sorting and generating all combinations.
        Space Complexity:- O(n + 2^n + n) -> for storing the combinations and the recursive stack space.
        */
        // set<vector<int>> st;
        // vector<int> temp;
        // solve1(candidates, n, 0, target, temp, st);
        // return {st.begin(), st.end()};


        /*
        Method - 2: Using sorting and skipping duplicates to avoid using set
        Time Complexity:- O(nlogn + 2^n) -> for sorting and generating all combinations.
        Space Complexity:- O(n + 2^n) -> for storing the combinations and the recursive stack space.
        */
        vector<int> temp;
        vector<vector<int>> ans;

        solve2(candidates, n, 0, target, temp, ans);

        return ans;
    }
private:
    // It is recursive function that generates the subset from ind to n-1 and add the subset to ans if the sum of the subset is equal to target.
    void solve2(vector<int> &candidates, int n, int ind, int target, vector<int> &temp, vector<vector<int>> &ans){
        if(target < 0){
            return;
        }

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < n; i++){
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }

            temp.push_back(candidates[i]);
            solve2(candidates, n, i + 1, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }

    void solve1(vector<int> &candidates, int n, int i, int target, vector<int> &temp, set<vector<int>> &st){
        if(target < 0){
            return;
        }

        if(target == 0){
            st.insert(temp);
            return;
        }

        if(i == n){
            return;
        }


        // take 
        temp.push_back(candidates[i]);
        solve1(candidates, n, i + 1, target - candidates[i], temp, st);
        temp.pop_back(); 

        // not take
        solve1(candidates, n, i + 1, target, temp, st);
    }
};

