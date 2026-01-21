#include<bits/stdc++.h>
using namespace std;

// brute force
double myPow(double x, int times){
    double ans = 1.0;
    for(int i =0 ; i<times; i++){
        ans = ans * x;
    }
    return ans;
}

// optimal 
double myPow2(double x, int times){
    double ans = 1.0;
    long long n = times;
    if(times<0) n = -1*n;
    while(n){
        if(n%2) {
            ans =ans * x;
            n = n-1;
        }
        else{
            x =x *x;
            n=n/2;
        }
    }
    if(times < 0) ans = (double)(1.0)/(double)(ans);
    return ans;

}

int main()
{
    cout<<myPow2(2,10)<<endl;
}