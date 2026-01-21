//Aggressive Cows
#include <bits/stdc++.h>
using namespace std;

int countstudents(vector<int> &nums, int pages){
    int n = nums.size();
    int students = 1;
    long long pagesstudent = 0;
    for(int i =0; i<n; i++){
        if(pagesstudent+ nums[i] <= pages){
            pagesstudent +=nums[i];
        }
        else{
            students ++;
            pagesstudent =nums[i];


        }

    }
    return students;

}

int splitArray(vector<int> &nums, int k ){
    int n = nums.size();
    if (n<k) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    while(low <= high){
        int mid = (low + high)/2;
        int count = countstudents(nums,mid);
        if(count <= k){
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    return low;
}