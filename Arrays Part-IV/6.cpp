/*
Method 1: Brute Force

    Use a frequency array of size 256 (since total ASCII characters = 256) or a set.

    For every starting index i, expand the substring and check for duplicate characters.

    Reset the frequency/set for each new i.

    Track the maximum length of substring without repeating characters.

Method 2: Optimal (Sliding Window)

    Use two pointers l and r, both starting at 0.

    Maintain a set to store characters in the current window.

    Steps:

        If s[r] is not present in the set:

            Insert s[r] into the set.

            Update the maximum length as max(len, r - l + 1).

            Move r to the right.

        If s[r] already exists in the set:

            Remove s[l] from the set.

            Move l to the right.

        Repeat until r reaches the end of the string.

    Time Complexity

        1. Each character is inserted once and removed once from the set.
        2. l and r both move forward at most n times.
        3. set operations (find, insert, erase) take O(log n).

    👉 Overall Time Complexity:
        O(nlogn)
    👉 Space Complexity:
        O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // return solve1(s, n);
        // return solve2(s, n);
        return solve3(s, n);
    }
private:
    int solve3(string s, int n){
        int l = 0;
        int r = 0;
        set<char> st;
        int len = 0;

        while(l < n && r < n){
            if(st.find(s[r]) == st.end()){
                len = max(len, r - l + 1);
                st.insert(s[r]);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        }

        return len;
    }

    int solve2(string s, int n){
        int ans = 0;

        for(int i=0;i<n;i++){
            set<char> st;

            for(int j=i;j<n;j++){
                if(st.find(s[j]) != st.end()){
                    break;
                }

                st.insert(s[j]);
                ans = max(ans, j - i + 1);
            }
        }
        
        return ans;
    }

    int solve1(string s, int n){
        int ans = 0;

        for(int i=0;i<n;i++){
            vector<int> freq(256, 0);

            for(int j=i;j<n;j++){
                if(freq[s[j]] > 0){
                    break;
                }

                freq[s[j]]++;
                ans = max(ans, j - i + 1);
                
            }
        }
        
        return ans;
    }
};