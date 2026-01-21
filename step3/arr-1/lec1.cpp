//chek if an array is sorted

#include<bits/stdc++.h>
using namespace std;
//brute force 
bool sortted(int arr[], int n){
    for(int i=0; i<n;i++) {
        for(int j=i+1; j<n; j++){
            if (arr[j] < arr[i]) return false;}
        }
        return true;

}

//optimum approch
bool issorted(int arr[], int n){
    for(int i=0; i<n;i++) {
            if (arr[i] < arr[i -1]) return false;
        }
        return true;

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    bool ans = issorted(arr, n);
    if (ans) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}