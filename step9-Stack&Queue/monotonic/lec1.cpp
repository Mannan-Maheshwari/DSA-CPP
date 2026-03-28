// Next Greater Element Using Stack

#include<bits/stdc++.h>
using namespace std;

// Solution class to find next greater elements
class Solution {
public:
    vector<int> nextgreator(vector<int> &nums){
        stack<int> st;
        int n = nums.size();
        vector<int> result(n);
    
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i]) st.pop();
            if(st.empty()) result[i] = -1;
            else{
                result[i] = st.top();
            }
            st.push(nums[i]);
        }
        return result;
    }
};


// Main function
int main() {
    vector<int> nums = {4, 5, 2, 10};
    Solution sol;
    vector<int> ans = sol.nextgreator(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}