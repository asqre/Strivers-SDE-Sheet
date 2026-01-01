/* Approach
Method-1 
a. Distinct means use set it will remove duplicates
b. before inserting list into set, sort the list.
c. insert all set element into list, return that list.

Method-2
a. Use three pointers i, j, and k; fix i and j, and move k from j + 1 to n - 1.
b. For each (i, j), maintain a HashSet while moving k to check if target − (nums[i] + nums[j] + nums[k]) already exists.
c. Use long for sum calculation to avoid overflow, and store sorted quadruplets in a Set to handle duplicates.

Method-3
a. Sort the array and fix two pointers i and j.
b. Use two pointers left and right to find the remaining two elements whose sum matches the target.
c. Move pointers based on the sum, use long to avoid overflow, and store unique quadruplets.

*/

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        // return solve1(nums, target, n);
        // return solve2(nums, target, n);
        return solve3(nums, target, n);
    }

    static List<List<Integer>> solve3(int[] nums, int target, int n){
        List<List<Integer>> ans = new ArrayList<>();
        Set<List<Integer>> set = new HashSet<>();

        Arrays.sort(nums);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left = j + 1, right = n-1;

                while(left < right){
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == (long)target){
                        List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[left], nums[right]);
                        set.add(temp);
                        left++;
                        right--;
                    }else if(sum > target){
                        right--;
                    }else{
                        left++;
                    }
                }  
            }
        }

        ans.addAll(set);
        return ans;
    }

    static List<List<Integer>> solve2(int[] nums, int target, int n){
        List<List<Integer>> ans = new ArrayList<>();
        Set<List<Integer>> set = new HashSet<>();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // Store kth elements to detect 4th element
                Set<Long> tempSet = new HashSet<>();
                for(int k=j+1;k<n;k++){
                    long sum = (long)nums[i]+nums[j]+nums[k];
                    long fourth = (long)target - sum;

                    if(tempSet.contains(fourth)){
                        if(fourth >= Integer.MIN_VALUE && fourth <= Integer.MAX_VALUE){
                            List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[k], (int)fourth);
                            Collections.sort(temp);
                            set.add(temp);
                        }
                    }

                    tempSet.add((long)nums[k]);
                }
            }
        }

        ans.addAll(set);

        return ans;
    }

    

    static List<List<Integer>> solve1(int[] nums, int target, int n){
        List<List<Integer>> ans = new ArrayList<>();
        Set<List<Integer>> set = new HashSet<>();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long sum = (long)(nums[i] + nums[j] + nums[k] + nums[l]);

                        if(sum == target){
                            List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[k], nums[l]);
                            Collections.sort(temp);
                            set.add(temp);
                        }
                    }
                }
            }
        }

        ans.addAll(set);

        return ans;
    }
}