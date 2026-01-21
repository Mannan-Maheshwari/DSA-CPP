// find peak elements in 2d matrix

#include<bits/stdc++.h>
using namespace std;

int maxElement(vector<vector<int>> &mat, int n, int m, int col){
    int maxval = -1;
    int index =-1;
    for (int i = 0; i<n;i++){
        if(mat[i][col] > maxval){
            maxval = mat[i][col];
            index = i;
        }
    }
    return index;
}

int peak(vector<vector<int>> &mat, int n, int m){
    int low =0, high = m-1;
    while(low <= high){
        int mid = (low + high)/2;
        int row = maxElement(mat, n, m, mid);
        int left = mid -1 >= 0 ? mat[row][mid-1] : -1; 
        int right = mid +1 < 0 ? mat[row][mid+1] : -1; 

        if(mat[row][mid] > left && mat[row][mid] > right){
            return {row,mid};
        }
        else if(mat[row][mid] < left) high = mid -1;
        else low = mid +1;

    }
    return {-1,-1};
}

int main() {
    Solution sol;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    pair<int, int> ans = sol.peak(mat, n, m);
    cout << "Peak element is at (" << ans.first << ", " << ans.second << ")" << endl;
    cout << "Value: " << mat[ans.first][ans.second] << endl;
    return 0;
}