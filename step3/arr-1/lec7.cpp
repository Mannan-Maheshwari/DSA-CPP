//Find union of two arrays
#include<bits/stdc++.h>
using namespace std;

// brute force
vector<int> uni(vector<int> a, vector<int> b){
    map<int,int> mpp;
    vector <int> Union;
    for(int i=0; i<a.size(); i++){
        mpp[a[i]]++;
    }

    for(int i=0; i < b.size(); i++){
        mpp[b[i]]++;
    }
    for(auto & it: mpp){
        Union.push_back(it.first);
    }
    return Union;   
}

//better
vector<int> uni2(vector<int> a, vector<int> b){
    set <int> stt;
    vector<int> Union;

    for(int i=0; i< a.size(); i++){
        stt.insert(a[i]);
    }
    for(int i=0; i< b.size(); i++){
        stt.insert(b[i]);
    }
    for(auto & it: stt){
        Union.push_back(it);
    }
    return Union;
    
}

//optimum with 2 pointer approch
vector<int> uni3(vector<int> a, vector<int> b){
    int i=0,j=0;
    vector<int> Union;
      while (i < a.size() && j < b.size()) {
    if (a[i] <= b[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != a[i])
        Union.push_back(a[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != b[j])
        Union.push_back(b[j]);
      j++;
    }
  }
  while (i < a.size()) // IF any element left in a
  {
    if (Union.back() != a[i])
      Union.push_back(a[i]);
    i++;
  }
  while (j < b.size()) // If any elements left in b
  {
    if (Union.back() != b[j])
      Union.push_back(b[j]);
    j++;
  }
  return Union;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {4,5,6,7,8,9};
    
    vector<int> Union = uni3(a,b);
    for(auto & val:Union)
        cout <<  val << " ";
    return 0;
}