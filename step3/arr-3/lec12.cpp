#include<bits/stdc++.h>
using namespace std;
    
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MIN;
    int pref = 1, suff = 1;
    for (int i =0; i<n; i++){
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref *= nums[i];
        suff *= nums[n - i - 1];
        ans = max(ans,max(pref,suff));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}