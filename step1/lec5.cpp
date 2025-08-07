#include<bits/stdc++.h>
using namespace std;

//recursion 
//print name 5 times
int cnt = 0;
void rec(){
   if(cnt == 5)
    return;
    else{
        cout<<"mann\n";
        cnt++;
        rec();

    }
}
//print linearly from 1 to N
void rec2(int i,int n){
    if(i>n)
    return;
    else{
        cout << i << endl;
        rec2(i+1,n);
    }
}
//print linearly form N to 1
void rec3(int n){
    if(n<1)
    return;
    else{
        cout << n << endl;
        rec3(n-1);
    }
}
//print form N to 1 by backtrack
void rec4(int i , int n){
    if(i<1) return;
    else{
        rec4(i-1,n);
        cout << i << endl;
    }
}
//sum of first N numbers
void recsum(int n, int sum){
    if(n<1) {
        cout << sum;
        return;}
    else{
        recsum(n-1,sum+n);

    }
    //in main call recsum(n,0);
}
//factorial
int fact(int n){
    if(n == 0) return 1;
    else
        return n * fact(n-1);
    /* in main() 
        cin >> n;
        cout << fact(n) << endl; */
}
//reverse an array
void arrev(int r,int arr[],int n){
    if(r>=n/2) return;
    else{
        swap(arr[r], arr[n-r-1]);
        arrev(r+1, arr, n);
    }
    // int main(){
    //     int n;
    //     cin >> n;
    //     int arr[n];
    //     for(int r=0;r<n; r++) cin >> arr[r];
    //     arrev(0, arr, n);
    //     for(int r=0;r<n; r++) cout << arr[r] << endl;
    //     return 0;   
    // }

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int r=0;r<n; r++) cin >> arr[r];
    arrev(0, arr, n);
    for(int r=0;r<n; r++) cout << arr[r] << endl;
    return 0;   
}
