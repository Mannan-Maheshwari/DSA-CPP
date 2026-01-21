// how many times array has been rotated
#include <bits/stdc++.h>
using namespace std;

    int findMin(vector<int>& nums) {
    int target = INT_MAX;
    int n = nums.size();
    int low = 0 , high = n-1;
    int index =-1;
    while(low <= high){
        int mid = (low + high)/2;
        if( nums[low] <= nums[high]){
            target = min(target, nums[low]);
            index = low;
            break;
        }
        if(nums[mid] <= nums[high]){
            target = min(target, nums[mid]);
            high = mid -1;
            index = mid;
            }
        else{
            target = min(target, nums[low]);
            low = mid +1; 
            index = low;
            }

        }
        return index;
    }


int main() {
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int ans = findMin(nums);
    cout << "the array has been rotated by: " << ans << "\n";
    return 0;
}