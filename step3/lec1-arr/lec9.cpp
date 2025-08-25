//Count Maximum Consecutive One's in the array

#include<bits/stdc++.h>
using namespace std;

int zeros(vector<int> &a){
    int n= a.size();
        int count = 0;
        int maxi =0;
        for (int j=0; j<n; j++){
            if(a[j]==1){
                count++;
                maxi = max(maxi, count);
            }
            else{
                count = 0;
            }
            
        }
        return maxi;
}


int main(){
    vector<int> a = {1,1,0,1,0,1,1,1,1,0};
    int cont = zeros(a);
    cout << cont ;
}

