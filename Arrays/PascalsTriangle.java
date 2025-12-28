class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList();

        for(int i = 0; i<numRows;i++){
            int len = i + 1;

            List<Integer> temp = new ArrayList();
            for(int j = 0; j < len; j++){
                temp.add(1);
            }

            if(i <= 1){
                ans.add(temp);
                continue;
            }

            for(int k = 1; k < len-1; k++){
                int val = ans.get(i-1).get(k) + ans.get(i-1).get(k-1);
                temp.set(k, val);
            }

            ans.add(temp);
        }

        return ans;
    }
}