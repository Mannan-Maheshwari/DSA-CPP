// Find the repeating and missing numbers

#include<bits/stdc++.h>
using namespace std;

// optimal approch
vector<int> findMissingRepeatingNumbers(vector<int> &a){
    long long n = a.size();
    long long cnt = 0;
    long long Scnt = 0;
    long long r;
    long long m;
    long long sum = (n *(n+1))/2;
    long long Sqsum = (n*(n+1)*(2*n+1))/6;
    for(int i =0; i< n; i++){
        cnt += a[i];
        Scnt += (long long)a[i]*(long long)a[i];
    }
    long long val1 = cnt - sum;
    long long val2 = (Scnt - Sqsum)/val1;
    r = (val1 + val2) /2;
    m = r - val1;
    
    return {(int)r,(int)m};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}