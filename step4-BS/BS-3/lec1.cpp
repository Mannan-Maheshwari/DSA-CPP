// Find the row with maximum number of 1's

#include<bits/stdc++.h>
using namespace std;

//optimal approch
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int max_ones(vector<vector<int>> &arr,int n, int m){
    int count = 0;
    int index = -1;

    for (int i =0 ; i<n; i++){
        int count_one = m - lowerBound(arr[i], m, 1);
        if(count_one > count) {
            count = count_one;
            index =i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         max_ones(matrix, n, m) << '\n';
}