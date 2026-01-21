// check whether one string is a rotation of another

#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;
    string doubled = s + s;
    return doubled.find(goal) != string::npos;
}


int main() {
    string s = "abcde";
    string goal = "cdeab";

    if(rotateString(s, goal))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}