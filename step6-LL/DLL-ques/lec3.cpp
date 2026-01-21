// Remove duplicates from sorted DLL

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

Node* sortedDLL(Node* head){
    Node* temp = head;
    while(temp != NULL && temp -> next != NULL){
        Node* newtemp = temp -> next;
        while(newtemp != NULL && temp -> data == newtemp -> data){
            Node* duplicate = newtemp;
            newtemp = newtemp -> next;
            free(duplicate);
        }
        temp -> next = newtemp;
        if(newtemp != NULL) newtemp -> prev = temp;
        temp = temp -> next;
    }
    return head;

}

int main() {
    vector<int> arr = {1, 1, 1, 7, 7, 5, 4, 4};
    Node* head = convertArr2DLL(arr);

    head = sortedDLL(head);
    print(head);
    return 0;
}