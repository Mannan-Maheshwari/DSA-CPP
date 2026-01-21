// left rotate the array by 1

#include<bits/stdc++.h>
using namespace std;
// brute force
void left_shift(int arr[], int n){
    int temp[n];
    for(int i=1; i<n; i++){
        temp[i-1] = arr[i];
    }
    temp[n-1] = arr[0];
    for(int i=0; i<n; i++){
        cout << temp[i] << " ";
    }
}

//optimum
void left_shift2(int arr[], int n){
    int temp = arr[0];
    for(int i=0; i<n; i++){
        arr[i] = arr[i + 1];
    }
    arr[n-1] = temp;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}


int main(){
    int n =5;
    int arr[]= {10, 11, 15, 9 ,7};
    left_shift2(arr, n);

}