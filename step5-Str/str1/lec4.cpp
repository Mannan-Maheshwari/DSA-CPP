#include <bits/stdc++.h>
using namespace std;
// Longest Common Prefix

string longestCommonPrefix(vector<string> & str){
    int n = str.size();
    if(str.empty()) return "";
    sort(str.begin(), str.end());

    string first = str[0];
    string last = str[n-1];

    string ans = "";
    int midlength = min(first.size(), last.size());

    for (int i = 0; i < midlength; i++) {
        if (first[i] != last[i]) break;
        ans += first[i];
    }

    return ans;
}
int main() {

    // Input list of strings
    vector<string> input = {"interview", "internet", "internal", "interval"};

    // Get the result
    string result = longestCommonPrefix(input);

    // Print the result
    cout << "Longest Common Prefix: " << result << endl; 

    return 0;
}