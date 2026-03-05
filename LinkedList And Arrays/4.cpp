class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        /*
        Optimal approach
        Time complexity: O(3n)
        Space complexity: O(2n)
        Approach: We can find the maximum height of the left and right side of each element in the array. 
        Then we can find the minimum of the left and right maximum height. 
        If the minimum height is greater than or equal to the current height, 
        then we can trap water at that index. 
        The amount of water trapped at that index will be the difference between the minimum height and the current height.
        */
        return solve1(height, n);
    }

private:
    int solve1(vector<int> &height, int n){
        vector<int> left_max = findLeftHeight(height, n);
        vector<int> right_max = findRightHeight(height, n);

        int waterTrapped = 0;
        for(int i=0;i<n;i++){
            int minHeight = min(left_max[i], right_max[i]);

            if(minHeight >= height[i]){
                waterTrapped += minHeight - height[i];
            }
        }

        return waterTrapped;
    }

    vector<int> findLeftHeight(vector<int> &height, int n){
        int maxLeftHeight = 0;

        vector<int> left_max;
        for(auto h : height){
            left_max.push_back(maxLeftHeight);
            maxLeftHeight = max(maxLeftHeight, h);
        }

        return left_max;
    }

    vector<int> findRightHeight(vector<int> &height, int n){
        int maxRightHeight = 0;

        vector<int> right_max(n, 0);
        for(int i=n-1;i>=0;i--){
            right_max[i] = maxRightHeight;
            maxRightHeight = max(maxRightHeight, height[i]);
        }

        return right_max;
    }
};