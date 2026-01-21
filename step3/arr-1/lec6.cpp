#include<bits/stdc++.h>
using namespace std;

//linear search
int linear_search(int arr[], int n, int num){
    for(int i =0; i<n; i++){
        if(arr[i] == num) 
            return i;
    }
    return -1;
}

main(){
    int num;
    cin >> num;
    int arr[] = {1, 0, 2, 0, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = linear_search(arr, n, num);
    cout << val;
    return 0;
}