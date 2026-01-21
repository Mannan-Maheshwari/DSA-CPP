//Find the number that appears once, and other numbers twice.

#include<bits/stdc++.h>
using namespace std;

//better 
int twice(vector<int> &nums){
    int n = nums.size();
    for (int i=0; i<n-1; i+=2){
        if(nums[i] != nums[i+1]) return nums[i];
    }
    return nums[n-1];
}

//optimum with XOR will do afterwords
int getSingleElement(vector<int> &nums) {
    //size of the array:
    int n = nums.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

int main(){
    vector<int> nums ={1,2,1,2,6,4,6};
    sort(nums.begin(), nums.end());

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    int once = twice(nums);
    cout << once;
}
