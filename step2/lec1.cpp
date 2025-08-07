#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
            int min,temp;
        // code here
        for(int i=0; i<=n-2;i++){
            min =i; 
            for(int j=i; j<=n-1; j++){
                if(arr[j] < arr[min]){
                    min =j;
                }
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            }
        }
    
}

void bubble_sort(int arr[],int n){
    
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    selection_sort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;



}