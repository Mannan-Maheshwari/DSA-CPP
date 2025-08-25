//remove duplicate elements form an array
#include<bits/stdc++.h>
using namespace std;
//brute force     
int duplicate(int arr[], int n){
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    int k = st.size();
    int j = 0;
    for (int x: st){
        arr[j++] = x;
    }
    return k;
}

//optimum 
int duplicate2(int arr[], int n){
    int j =0;
    for(int i =0; i<n; i++){
        if(arr[j] != arr[i]){
            j++;
            arr[j] = arr[i];
        }

    }
    return j + 1;

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    int r = sizeof(arr)/sizeof(arr[0]);
    int k = duplicate2(arr,n);
    for (int i = 0; i<k; i++){
        cout << arr[i] << " ";
    }
}