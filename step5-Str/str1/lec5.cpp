#include <bits/stdc++.h>
using namespace std;

// Isomorphic String
bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;

    for (int i = 0; i < s.size(); i++) {
        char chS = s[i];
        char chT = t[i];

        if (mapST.find(chS) != mapST.end()) {
            if (mapST[chS] != chT) return false;
        } else {
            mapST[chS] = chT;
        }

        if (mapTS.find(chT) != mapTS.end()) {
            if (mapTS[chT] != chS) return false;
        } else {
            mapTS[chT] = chS;
        }
    }

    return true;
}
