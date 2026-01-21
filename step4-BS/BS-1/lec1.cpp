//Binary Search to find X in sorted array

#include <bits/stdc++.h>
using namespace std;

//iterative
int binary(vector<int> &nums, int x){
    int n= nums.size();
    int low =0 , high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if (nums[mid] == x) return mid;
        else if (nums[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

//recursive
int binary2(vector<int> &nums,int low, int high, int x){
    int n = nums.size();
    if (low>high) return -1;
    else {
        int mid = (low+ high)/2;
        if(nums[mid]== x) return mid;
        else if(x > nums[mid]){
            return (binary2(nums, mid +1, high, x));}
        else {
            return (binary2(nums, low, mid -1, x));
        }
        }
    }


int main(){
    int x;
    cin >> x;
    vector<int> nums = {10 ,12 ,16 ,21 , 22, 28, 30};
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int bs = binary2(nums, low, high, x);
    cout << bs << " ";
}
