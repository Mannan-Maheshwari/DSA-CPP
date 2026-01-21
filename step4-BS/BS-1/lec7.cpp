//Single element in a Sorted array

#include <bits/stdc++.h>
using namespace std;

int singEle(vector<int> &nums){
    int n = nums.size();
    int low = 1, high = n-2;
    if (nums[0] != nums[1]) return nums[0];
    else if (nums[n-1] != nums[n-2]) return nums[n-1];
    else{
        while(low <= high){
            int mid = (low+high)/2;
            if((nums[mid] != nums[mid+1])&& (nums[mid] != nums[mid-1]) )  return nums[mid];
            else{
                if(((mid%2 == 0) && (nums[mid]== nums[mid+1])) || ((mid % 2 == 1 ) && (nums[mid]== nums[mid-1]) )) //we are in the left half
                low = mid +1;
                else{
                    high = mid -1;
                }
            }
        }
        return -1;
    }
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    int ans = singEle(nums);
    cout << "The single element is: " << ans << "\n";
    return 0;
}