class Solution {
    public List<Integer> majorityElement(int[] nums) {
        // Boyer moores vote algorithm
        // for n/3 -> 2 atmost majority element
        // so, for 2 majority element, it required 2*2= 4 variable

        // Step 1: Find potential majority element
        int n = nums.length;
        int maj1 = 0;
        int cnt1 = 0;
        int maj2 = 0;
        int cnt2 = 0;

        for(int num : nums){
            if(num == maj1){
                cnt1++;
            }else if(num == maj2){
                cnt2++;
            }else if(cnt1 == 0){
                maj1 = num;
                cnt1++;
            }else if(cnt2 == 0){
                maj2 = num;
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        // 2nd Step: verify majority element
        cnt1 = 0;
        cnt2 = 0;

        for(int i : nums){
            if(maj1 == i){
                cnt1++;
            }else if(maj2 == i){
                cnt2++;
            }
        }
        
        List<Integer> ans = new ArrayList<>();
        if(cnt1 > n/3) ans.add(maj1);
        if(cnt2 > n/3) ans.add(maj2);

        return ans;
    }
}