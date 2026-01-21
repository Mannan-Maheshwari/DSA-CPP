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
        
Node* deletekey(Node* head, int key){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        if(temp -> data == key){
            if(temp == head){
                head = head -> next;
            }
            Node* nextnode = temp -> next;
            Node* prevnode = temp -> prev;
            if(nextnode){
                nextnode -> prev = prevnode;
            }
            if(prevnode){
                prevnode -> next = nextnode;
            }
            free(temp);
        }
        else{
        temp = temp -> next;}
    }
    return head;
}

int main() {
    vector<int> arr = {12, 5, 12, 7, 4};
    Node* head = convertArr2DLL(arr);

    head = deletekey(head,12);
    print(head);
    return 0;
}