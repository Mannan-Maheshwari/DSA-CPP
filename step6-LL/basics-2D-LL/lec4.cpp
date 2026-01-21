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

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";  
        head = head->next;         
    }
}
// for the brute force we can have the data in stack using LIFO it will apne app revese it

// optimal approch
Node* reverse(Node* head){
    Node* p = NULL;
    Node* current = head;
    while (current != NULL)
    {
        p = current -> prev;
        current -> prev = current -> next;
        current -> next = p;
        current = current -> prev;
    }
    return p -> prev;
    
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    head = reverse(head);
    print(head);
    return 0;
}