// Search in Rotated Sorted Array 1
#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0 , high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid]== target) return mid;
        if(nums[mid] <= nums[high]){
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
            else{
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid +1;
                }
            }
            
        }
        return -1;
    }
    
    // Search in Rotated Sorted Array 1
        bool search2(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0 , high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low +1;
                high = high -1;
                continue;
            }
            if(nums[mid] <= nums[high]){
                if(nums[mid]<= target && target <= nums[high]){
                    low = mid +1;
                }
                else high = mid -1;
            }
            else{
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid -1;
                }
                else low = mid +1;
            }

            
        }
        return false;
    }

    int main(){
        vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
        int n = nums.size();
        int target;
        cin >> target;
        int ans = search2(nums,target);
        if (ans == -1)
            cout << "Target is not present.\n";
        else
            cout << "The index is: " << ans << "\n";
        return 0;
    }