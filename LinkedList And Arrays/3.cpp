class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        /*
        Method - 1 
        Brute force
        using three pointer
        T.c = O(n^3)
        S.C = O(no of triplets) * 2 = 2* no of triplets. because one we storing all the triplets into set and other we are storing 
                all the triplet into ans vector.
        */

        // return solve1(nums, n);
       
       /*
        Method -2
        using two pointer by checking third element into hashset
        T.C = o(n^2 * log(x)* 3log3) ; where x is no of triplets
        S.C = O(2*x + n); where 2* x because no of triplets storing in set and ans. and n is no of element storing in hashset
       */
        // return solve2(nums, n);

        /*
        Method - 3
        Using three pointer i, j & k. by keeping i as const
        T.C = O(n^2)
        S.c = O(x), to store no of triplets into ans
        */
        return solve3(nums, n);
    }

private:
    vector<vector<int>> solve3(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = n - 1;


            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j-1] == nums[j]){
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
            }
        }

        return ans;
    }

    vector<vector<int>> solve2(vector<int>& nums, int n) {
        set<vector<int>> st; // we can unordered set here.

        for(int i=0;i<n;i++){
            unordered_set<int> hashSet; // we can use unordered set here, coz it contains integer.
            for(int j=i+1;j<n;j++){
                int third = -(nums[i] + nums[j]);

                if(hashSet.find(third) != hashSet.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }

    vector<vector<int>> solve1(vector<int>& nums, int n) {
        set<vector<int>> s;

        for(int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for(auto it : s){
            ans.push_back(it);
        }
        
        return ans;
    }
};