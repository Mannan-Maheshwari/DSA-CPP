#include<bits/stdc++.h>
using namespace std;

void merge(vector <int> &arr, int low , int mid, int high){
    vector <int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left ++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    
    
    
}
void merge_sort(vector <int> &arr, int low, int high){
    if(low >= high) return;
    else{
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int fn(vector <int> &arr, int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while (arr[i]<=pivot && i <= high-1 )
        {
            i++;
        }
        while (arr[j] > pivot && j >= low+1 )
        {
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector <int> &arr, int low ,int high){
    if(low<high){
        int p_index = fn(arr,low, high);
        qs(arr, low, p_index-1);
        qs(arr, p_index +1, high);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0; i<n; i++){
        cin >> arr[i];

    }

    merge_sort(arr, 0, n-1);
    qs(arr, 0, arr.size()-1);
    for(int i =0; i<n; i++){
        cout << arr[i] << " ";

    }
    return 0;
}