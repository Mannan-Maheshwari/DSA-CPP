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

Node* deleteatstart(Node* head){
    Node* temp = head;
    head = head -> next;
    temp -> next = nullptr;
    head -> prev = nullptr;
    free(temp);
    return head;

}

Node* deleteatend(Node* head){
    Node* temp = head;
    if(head == NULL || head -> next == NULL) return NULL;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* p = temp -> prev;
    p -> next = nullptr;
    temp -> prev = nullptr;
    free(temp);
    return head;
}

Node* deleteatposition(Node* head, int k){
    Node* temp = head;
    int cnt = 0;
    if(k == 1){
        return deleteatstart(head);
    }
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp -> next;
    }
    Node* p = temp -> prev;
    Node* n = temp -> next;
    p -> next = n;
    n -> prev = p;
    temp -> prev = nullptr;
    temp -> next = nullptr;
    free(temp);
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

     // delete a node
    head = deleteatposition(head , 1);
    print(head);
    return 0;
}