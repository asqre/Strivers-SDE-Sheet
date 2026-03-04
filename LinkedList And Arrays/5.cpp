class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        /*
        Method-1
        Brute force 
        using hash map to store all duplicates with their val and their count
        T.C = O(n + 2k)
        S.C = O(2K); where k is no of unique element
        */
        // return solve1(nums, n);

        /*
        Method - 2 
        Optimized 
        using two pointer approach
        */
        return solve2(nums, n);
    }

private:
    int solve2(vector<int> &nums, int n){
        int i=0;

        for(int j=1;j<n;j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }

    int solve1(vector<int> &nums, int n){
        map<int, int> m;

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        int ans = m.size();

        int i = 0;
        for(auto &it : m){
            nums[i] = it.first;
            it.second--;
            i++;
        }

        for(auto &it : m){
            while(it.second){
                nums[i] = it.first;
                i++;
                it.second--;
            }
        }

        return ans;
    }
};