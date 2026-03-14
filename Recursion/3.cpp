/*
Recursion + Backtracking
Time Complexity:- O(nlogn + 2^n) -> for sorting and generating all combinations.
Space Complexity:- O(n + 2^n + n) -> for storing the combinations and the recursive stack space.
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        // set<vector<int>> st;
        // solve1(candidates, n, 0, target, temp, st);
        // return {st.begin(), st.end()};

        vector<vector<int>> ans;
        solve2(candidates, n, 0, target, temp, ans);
        return ans;
    }
private:
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
        solve1(candidates, n, i, target - candidates[i], temp, st);
        temp.pop_back(); 

        // not take
        solve1(candidates, n, i + 1, target, temp, st);
    }

    void solve2(vector<int> &candidates, int n, int ind, int target, vector<int> &temp, vector<vector<int>> &ans){
        if(target < 0){
            return;
        }

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < n; i++){
            if(i > ind && candidates[i] == candidates[i - 1]) continue;

            temp.push_back(candidates[i]);
            solve2(candidates, n, i, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }
};



