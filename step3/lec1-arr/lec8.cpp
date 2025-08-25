//find missing number in an array
#include<bits/stdc++.h>
using namespace std;

//brute force 
vector<int> miss(vector<int> &a){
    int n= a.size();
    for(int i=1; i<n; i++){
        int flag =0;
        for(int j=0; j<n-1; j++){
            if(a[j] == i ){ 
                flag =1;
                break;
            }
        }
        if(flag == 0) return {i};

    }
    return {-1};
}
//better 
int missingNumber(vector<int>&a, int N) {

    int hash[N + 1] = {0}; //hash array

    // storing the frequencies:
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;

    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

//optimal by summation 
vector<int> miss2(vector<int> a){
    int n= a.size();
    int sum = (n*(n+1))/2;

    int s =0;
    for(int i =0; i< n-1; i++){
        s += a[i];
    }

    return {sum - s};
}
//optimum approch by xor *(didn't try it (just a copy to revise))
int missingNumber(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}
int main(){
    vector<int> a = {1,2,4,5,6};
    vector<int> b = miss2(a);
    for(int num : b) {
        cout << num << " ";
    }
}