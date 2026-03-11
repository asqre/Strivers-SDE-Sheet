class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /*
        Greedy Approach:
        1. Sort both vectors in ascending order.
        2. Use two pointers to traverse both vectors.
        3. If the current cookie size is greater than or equal to the current child's greed, assign the cookie and move both pointers.
        4. Otherwise, move the cookie pointer to the next cookie.
        5. Return the number of assigned cookies.
        Time Complexity: O(nlogn + mlogm) where n is the number of children and m is the number of cookies.
        Space Complexity: O(1) if we ignore the space used for sorting, otherwise O(n + m) for the sorting space.
        */
        return solve1(g, s);
    }
private:
    int solve1(vector<int> &g, vector<int> &s){
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int assignedCookie = 0;

        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                assignedCookie++;
                j++;
                i++;
            }else{
                j++;
            }
        }

        return assignedCookie;
    }
};

