#include<bits/stdc++.h>
using namespace std;

long long goodno(int n){
    long long cnt =1;
    for(int i=0;i<n;i++){
        if(i%2){
            cnt = cnt*5;
            continue;
        }
        else{
            cnt = cnt * 4;
            continue;
        }
    }
    return cnt;
}

int main() {
    int n = 1;
    cout << goodno(n) << endl;
    return 0;
}