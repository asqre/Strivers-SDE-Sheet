int solve1(int at[], int dt[], int n){
    int minPlatform = 0;

    for(int i = 0; i < n; i++){
        int platforms = 0;

        int time = at[i]; // arrival time

        for(int j = 0; j < n; j++){
            if(at[j] <= time && time <= dt[j]){
                platforms++;
            }
        }

        minPlatform = max(minPlatform, platforms);
    }

    return minPlatform;
}

int solve2(int at[], int dt[], int n){
    vector<pair<int, char>> time;

    for(int i = 0; i < n; i++){
        time.push_back({at[i], 'A'});
        time.push_back({dt[i], 'D'});
    }

    sort(time.begin(), time.end());

    int minPlatform = 0;

    int platformsReq = 0;

    for(auto p : time){
        if(p.second == 'A'){
            platformsReq++;
        }else if(p.second == 'D'){
            platformsReq--;
        }

        minPlatform = max(minPlatform, platformsReq);
    }

    return minPlatform;
}

int solve3(int at[], int dt[], int n){
    sort(at, at + n);
    sort(dt, dt + n);

    int minPlatform = 0;

    int platformsReq = 0;

    int i = 0, j = 0;

    while(i < n && j < n){
        if(at[i] <= dt[j]){
            platformsReq++;
            i++;
        }else{
            platformsReq--;
            j++;
        }

        minPlatform = max(minPlatform, platformsReq);
    }

    return minPlatform;
}

int calculateMinPatforms(int at[], int dt[], int n) {
    /*
    Brute Force Approach
    T.C = O(N^2)
    S.C = O(1)
    At the arrival time of each train, count how many trains are present at the station.
    The maximum count across all arrival times will be the minimum number of platforms needed.
    */
    // return solve1(at, dt, n);

    /*
    Method -2 
    Optimized Approach
    T.C = O(NlogN) + O(N) ~ O(NlogN)
    S.C = O(2N)
    We can create a list of all arrival and departure times, marking them as 'A' for arrival and 'D' for departure. Then we can sort this list based on time.
    We can iterate through the sorted list and keep a count of how many trains are currently at the station. Whenever we encounter an 'A', we increment the count,
    and whenever we encounter a 'D', we decrement the count. The maximum value of this count during the iteration will give us the minimum number of platforms needed.
    */
    // return solve2(at, dt, n);


    /*
    Method -3
    Optimal Approach
    T.C = O(2NlogN) + O(2N) ~ O(NlogN)
    S.C = O(N) // to sort the arrival and departure times
    We can sort the arrival and departure times separately. Then we can use two pointers to traverse both arrays. We can compare the current arrival time with the current departure time. 
    If the arrival time is less than or equal to the departure time, it means a train has arrived before the previous one has departed, so we need an additional platform.
    If the arrival time is greater than the departure time, it means a train has departed before the next one arrives, so we can free up a platform. 
    */

    return solve3(at, dt, n);
}

