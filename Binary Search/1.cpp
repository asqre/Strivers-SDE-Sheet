/*
The Nth root of m lies between 1 and m, so apply binary search in this range.
Pick mid and calculate midⁿ using fast power (divide and conquer).
If midⁿ equals m, return mid.
If midⁿ is greater than m, move to the left (end = mid - 1).
If midⁿ is smaller than m, move to the right (start = mid + 1).
If no value satisfies the condition, return -1.
*/


double pow(int x, int n){
    if(n == 0){
        return 1;
    }

    double ans = pow(x, n/2);
    ans *= ans;

    if(n % 2 != 0){
        ans *= x;
    }

    return ans;
}

int solve1(int n, int m){
    int s = 1;
    int e = m;

    while(s <= e){
        int mid = s + (e - s)/2;

        double power = pow(mid, n);

        if(power == m){
            return mid;
        }

        if(power > m){
            e = mid -1;
        }else{
            s = mid + 1;
        }
    }

    return -1;
}

int NthRoot(int n, int m) {
  // Write your code here.
  return solve1(n, m);
}