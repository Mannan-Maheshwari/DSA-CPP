//Find the first or last occurrence of a given number in a sorted array
#include <bits/stdc++.h>
using namespace std;
       

    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lb == n || nums[lb] != target) return {-1, -1};
        return {lb, ub - 1};
    }

    int main(){
    int target;
    cin >> target;
    vector<int> nums = {5,7,7,8,8,10};
    int n = nums.size();
    vector<int> bs = searchRange(nums, target);
    for (int x : bs) cout << x << " ";
    }


    //Count occurrences of a number in a sorted array with duplicates
    /* just do upper - lower + 1 
        ex -[1, 2, 8,8, 9]
         so 3-2+1 (indexes) so the count is 2 of 8*/