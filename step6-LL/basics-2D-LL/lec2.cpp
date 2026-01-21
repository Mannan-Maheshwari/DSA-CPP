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

Node* insertatHead(Node* head, int val){
    Node* newhead = new Node(val, head ,nullptr);
    head -> prev = newhead;
    return newhead;
}

Node* insertatTail(Node* head, int val){
    Node* end = new Node(val);
    if (head == nullptr) {
        return end;
    }
    Node* tail = head;
    while (tail -> next != nullptr)
    {
        tail = tail -> next;
    }
    tail -> next = end;
    end -> prev = tail;
    return head;
}

Node* insertatposition(Node* head, int val, int k){
    if(k == 1){
        insertatHead(head,val);
    }
    
    Node* temp =head;
    int cnt =0;
    while(temp -> next != NULL){
        cnt = cnt + 1;
        if(cnt == k) break;
        temp = temp -> next;
    }
        Node* previous = temp -> prev;
        Node* insert= new Node(val,temp,previous);
        previous -> next = insert;
        temp -> prev = insert;
        return head;
    

}
int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

     // Insert a node with value 10 at the end
    head = insertatposition(head, 10);
    print(head);

    return 0;
}