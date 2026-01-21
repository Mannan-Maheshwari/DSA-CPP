// Remove outermost Paranthesis
#include <bits/stdc++.h>
using namespace std;

string paranthesis(string s){
    int n = s.size();
    int count =0;
    string ans ="";
    for (int i =0 ; i<n ; i++){
        if(s[i] == ')') count--;
        if(count != 0) ans.push_back(s[i]);
        if(s[i] == '(') count++;
        
    }
    return ans;
}


int main(){
    string s = "(()())(())";
    
    cout << paranthesis(s) ;
}
