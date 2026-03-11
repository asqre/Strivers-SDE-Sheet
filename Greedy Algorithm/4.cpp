#include <bits/stdc++.h> 

bool comp(pair<int, int> &p1, pair<int, int> &p2){
    double valOfUnitItem1 = (double)p1.second / p1.first;    
    double valOfUnitItem2 = (double)p2.second / p2.first;

    return valOfUnitItem1 > valOfUnitItem2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    /*
    Greedy Approach
    T.C = O(NlogN) + O(N) ~ O(NlogN)
    S.C = O(N) for sorting
    To make knapsack value maximum, we can put those items in the knapsack which have maximum value per unit weight,
    i.e, ratio of value to weight is maximum. 
    We can sort the items based on this ratio in descending order 
    */

    sort(items.begin(), items.end(), comp);

    int currWeight = 0;
    double maxValue = 0;

    for(int i = 0; i < n; i++){
        if(items[i].first + currWeight <= w){
            currWeight += items[i].first;
            maxValue += (double)items[i].second;
        }else{
            int remainingWeight = w - currWeight;
            currWeight += remainingWeight;
            maxValue += ((double)items[i].second / items[i].first)*remainingWeight;
            break;
        }
    }

    return maxValue;
}