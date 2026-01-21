
#include <bits/stdc++.h>
using namespace std;


// 3 Sum : Find triplets that add up to a zero

//brute 
vector<vector<int>> triplets(vector<int> &arr){
    int n =arr.size();
    set<vector<int>> st; 
    for(int i=0;i<n;i++){
        for(int j =i+1; j<n;j++){
            for(int k =j+1; k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> temp= {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//optimum
vector<vector<int>> triplets2(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates for i
        int j = i+1;
        int k = n-1;
        while (j<k){
            if(nums[i]+nums[j]+nums[k] < 0){
                j++;
            }
            else if(nums[i]+nums[j]+nums[k] > 0){
                k--;
            }
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;

                // (Optional) Skip duplicates to avoid unnecessary set insertions:
                while (j < k && nums[j] == nums[j-1]) j++;
                while (j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = triplets2(arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
