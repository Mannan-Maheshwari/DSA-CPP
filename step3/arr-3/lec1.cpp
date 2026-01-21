// Program to generate Pascal's Triangle
#include <bits/stdc++.h>
using namespace std;

// Question variation 1
int ncr(int n, int r){
    long long res =1;

    for(int i=0 ;i<r; i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;

}

int pascalTriangle(int r, int c) {
    int element = ncr(r - 1, c - 1);
    return element;
}

// Question variation 2
void pascalTriangle2(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << ncr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

// int main()
// {
//     int r = 5; // row number
//     int c = 3; // col number
//     int n =5;
//     pascalTriangle2(r);
//     // cout << "The element at position (r,c) is: " << element;
//     return 0;
// }

//Question variation 3

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(ncr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}