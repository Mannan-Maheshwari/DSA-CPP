#include <bits/stdc++.h>
using namespace std;

int bananas(vector<int> &piles, int h ){
        int k =0;
        int n = piles.size();

        for(int i = 0; i < n; i++) {
            k += ceil((double)(piles[i]) / (double)(h));
        }
        return k;
    }

int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxPile;
        while(low<=high){
            int mid = (low +high)/2;
            int totalH = bananas(piles, h);
        while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = bananas(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
}


int main(){
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minEatingSpeed(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}