#include<bits/stdc++.h>
using namespace std;

//brute force
void zero_end(int arr[], int n, int k ){
    int temp = arr[k];
    for(int i=0; i<n; i++){
        arr[i] = temp;
    }
    temp = arr[n-k];
}

main(){
    int n =5;
    int k =3;
    int arr[] = {1, 0, 2, 0, 3};
    zero_end(arr, n, k);
    for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    return 0;
}