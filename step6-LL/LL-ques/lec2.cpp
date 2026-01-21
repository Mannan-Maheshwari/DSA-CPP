#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// iterative method
Node* reverseLL(Node* head){
    Node* t1 = head;
    Node* t2 = head ->next;
    if(head == NULL || head -> next == NULL) return head;
    Node* prev =NULL;

    while(t1 != NULL){
        t2 = t1 -> next;
        t1 -> next = prev;
        prev = t1;
        t1 =t2;
    }
    return prev;    
}

// recursive method
Node* reverseLL2(Node* head){
    if(head == NULL || head -> next == NULL) return head;
    Node* newhead = reverseLL2(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = NULL;
    return newhead;

}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLL2(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}