#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }

    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }

};

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* insertHead(Node* head,int val){
    Node* temp = new Node(val,head);
    return temp;
}

Node* insertTail(Node* head, int val){
    Node* temp = head;
    if(head == NULL){
        return new Node(val);
    }
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node*w = new Node(val);
    temp -> next = w;
    return head;
}

Node* insertelement(Node* head, int val, int position){
    if(head == NULL){
        if(position == 1) return new Node(val);
        else return NULL;
    }
    if(position ==1){
        Node * atstart = new Node(val);
        return atstart;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt ++;
        if(position == cnt -1){
            Node* newEle = new Node(val);
            newEle -> next = temp -> next; // first this then the next line (phele new element ka next point karega age fir temp ka next point karega new element ko)
            temp -> next = newEle;
            break;
        }
        temp = temp -> next;
    }
    return head;

}
int main() {
    // Sample array and value for insertion
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Inserting a new node at the head of the linked list
    head = insertelement(head, val,2);

    // Printing the linked list
    printLL(head);

    return 0;
}