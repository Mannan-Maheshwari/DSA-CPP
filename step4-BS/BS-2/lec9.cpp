// Book Allocation Problem
// Painter's partition
// Split array - Largest Sum
//all of these problems have same approch and same solution

#include <bits/stdc++.h>
using namespace std;

int countstudents(vector<int> &arr, int pages){
    int n = arr.size();
    int students = 1;
    long long pagesstudent = 0;
    for(int i =0; i<n; i++){
        if(pagesstudent+ arr[i] <= pages){
            pagesstudent +=arr[i];
        }
        else{
            students ++;
            pagesstudent =arr[i];


        }

    }
    return students;

}

int allocate(vector<int> &arr, int m){
    int n = arr.size();
    if (n<m) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high){
        int mid = (low + high)/2;
        int count = countstudents(arr,mid);
        if(count <= m){
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    return low;
}


int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    int ans = allocate(arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}