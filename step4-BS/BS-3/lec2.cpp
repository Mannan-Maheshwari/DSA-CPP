// Search in a sorted 2D matrix
#include<bits/stdc++.h>
using namespace std;

// brute force
bool search_mat1(vector<vector<int>> &arr,int target){
    int n =arr.size();
    int m =arr[0].size();
    for(int i =0; i< n; i++){
        for(int j =0; j<m; j++){
            if(arr[i][j] == target) return true;
        }
    }
    return false;
}

// better
int bn(vector<int> &nums,int target){
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

bool search_mat2(vector<vector<int>> &arr,int target){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int bin = bn(arr[i], target);
        if(bin != -1) return true;
    }
    return false;
}

// optimal 
bool search_mat3(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1; // traverse the whole array.
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main()
{
    int val;
    cin >> val;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    search_mat3(matrix, val) == true ? cout << "true\n" : cout << "false\n";
}