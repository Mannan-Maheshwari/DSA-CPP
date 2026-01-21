// Find pairs with given sum in DLL

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int data1,Node* next1,Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

};

Node* convertArr2DLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; 
        prev = temp;       
    }
    return head;  
}


vector<pair<int, int>> findpairs(Node* head, int key) {
    vector<pair<int, int>> ds;
    if (!head) return ds;

    Node* left = head;
    Node* right = head;

    // Move right pointer to the tail
    while (right->next) right = right->next;

    // Two-pointer approach
    while (left && right && left != right && left->prev != right) {
        int sum = left->data + right->data;
        if (sum == key) {
            ds.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if (sum < key) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }

    return ds;
}

int main() {
    vector<int> arr = {1, 4, 5, 7, 11};
    int key = 12;

    Node* head = convertArr2DLL(arr);
    vector<pair<int, int>> pairs = findpairs(head, key);

    if (pairs.size() == 0) {
        cout << "No pairs found" << endl;
    } else {
        cout << "Pairs with sum " << key << ":" << endl;
        for (int i = 0; i < pairs.size(); i++) {
            cout << pairs[i].first << " " << pairs[i].second << endl;
        }
    }

    return 0;
}