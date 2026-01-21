// Capacity to Ship Packages within D Days
#include <bits/stdc++.h>
using namespace std;

int Tcapacity(vector<int> &arr, int m){
    int days = 1; //First day.
    int load = 0;
    int n = arr.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + arr[i] > m) {
            days += 1; //move to next day
            load = arr[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += arr[i];
        }
    }
    return days;
}

int capacity(vector<int> &arr, int k){
    int n = arr.size();
    int maxi = *max_element(arr.begin(),arr.end());
    int low = maxi, high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low+high)/2;
        int totalCp = Tcapacity(arr, mid);
        if(totalCp <= k){
            high =mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;


}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int d = 5;
    int ans = capacity(arr, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}