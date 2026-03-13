vector<int> solve1(vector<int> &nums, int n){
	vector<int> ans;

	for(int sub = 0; sub < (1 << n); sub++){
		int sum = 0; 

		for(int i = 0; i < n; i++){
			if((sub & (1 << i)) != 0){ // means ith index is the bit of subset
				sum += nums[i];
			}
		}

		ans.push_back(sum);
	}

	sort(ans.begin(), ans.end());

	return ans;
}

void solve2(vector<int> &nums, int n, int i, int sum, vector<int> &ans){
	if(i == n) {
		ans.push_back(sum);
		return;
	}

	// take
	solve2(nums, n, i + 1, sum + nums[i], ans);

	//not take
	solve2(nums, n, i + 1, sum, ans);
}

vector<int> subsetSum(vector<int> &nums){
	// Write your code here.
	int n = nums.size();

	/*
	Method - 1  -> Bit Manipulation
    Time Complexity: O(n * 2^n + 2^n log(2^n)) -> for generating all subsets and sorting them.
    Space Complexity: O(2^n) -> for storing the sums of all subsets.
	*/
	// return solve1(nums, n);

    /*
    Method - 2 -> Recursion
    Time Complexity: O(2^n) -> for generating all subsets.
    Space Complexity: O(2^n) -> for storing the sums of all subsets.
    */
	vector<int> ans;
	solve2(nums, n, 0, 0, ans);
	sort(ans.begin(), ans.end());
	return ans;	
}