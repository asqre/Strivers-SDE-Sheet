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
        set<vector<int>> st;
        vector<int> temp;
        solve1(candidates, n, 0, target, temp, st);
        return {st.begin(), st.end()};
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
};

