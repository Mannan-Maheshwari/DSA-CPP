#include <bits/stdc++.h>
using namespace std;


    // brute force
    vector<vector<int>> triplets(vector<int> &arr ,int target){
    int n =arr.size();
    set<vector<int>> st; 
    for(int i=0;i<n;i++){
        for(int j =i+1; j<n;j++){
            for(int k =j+1; k<n;k++){
                for(int l =k+1; l<n; l++){

                    if(arr[i]+arr[j]+arr[k] == target){
                        vector<int> temp= {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> triplets2(vector<int> &nums,int target){
            int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for(int l=n-1;l>0; l--){

            if (l < n - 1 && nums[l] == nums[l + 1]) continue; // skip duplicates for l
            int j = i+1;
            int k = l-1;
            while (j<k){
                long long sum = 1LL*nums[i]+nums[j]+nums[k]+nums[l]; // stop the overflow.
                if(sum< target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    j++;
                    k--;
    
                    // (Optional) Skip duplicates to avoid unnecessary set insertions:
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
    }
    return ans;
    
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = triplets2(nums,target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}