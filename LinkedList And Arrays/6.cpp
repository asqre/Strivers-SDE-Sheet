class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        return solve1(nums, n);
    }
private:
    int solve1(vector<int> &nums, int n){
        int ans = 0;
        int cnt = 0;

        for(auto num : nums){
            if(num == 0){
                cnt = 0;
            }else{
                cnt++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};