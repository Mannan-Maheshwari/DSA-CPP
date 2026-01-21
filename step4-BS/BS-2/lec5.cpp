// Find the smallest Divisor

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int summ(vector<int>& nums, int m) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(nums[i]) / (double)(m));
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    if (n > threshold) return -1;
    int ans = -1;
    int low = 1, high = *max_element(nums.begin(), nums.end());
    while (low <= high) {
        int mid = (low + high) / 2;
        if (summ(nums, mid) <= threshold) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int threshold = 8;
    int ans = smallestDivisor(nums, threshold);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}