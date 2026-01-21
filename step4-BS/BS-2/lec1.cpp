// Find square root of a number in log n

#include <bits/stdc++.h>
using namespace std;

//1st optimum
int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}

//2nd optimum
int sqroot(int nums){

    int low =0, high = nums-1;
    while(low <= high){
        long long mid = (high+ low)/2;
        long long val = mid*mid;
        if(val <= (long long)(nums)){
            low = mid + 1;
        }
        else{
            high = mid -1;

        }
        
    }
    return high;
}

int main()
{
    int nums = 28;

    int ans = sqroot(nums);
    cout << "The floor of square root of " << nums
         << " is: " << ans << "\n";
    return 0;
}