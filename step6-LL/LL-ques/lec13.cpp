#include <bits/stdc++.h>
using namespace std;

// Node class representing a single digit in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class to manage node-level operations
class LinkedList {
public:
    // function to insert digit at the end
    Node* append(Node* head, int value) {
        Node* newNode = new Node(value);
        if (!head) {
            return newNode;
        }
        Node* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        return head;
    }

    // Function to print the list
    void printList(Node* head) {
        Node* current = head;
        while (current) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};

Node* reverseList(Node* node) {
        Node* prev = nullptr;
        Node* current = node;

        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

// Function to add one to the number represented by the linked list
// itterative code
Node* addOne(Node* head) {
    head= reverseList(head);
    Node* temp = head;
    int carry = 1;

    while (temp != NULL){
        temp -> data = temp -> data + carry;
        if(temp -> data < 10){
            carry =0;
            break;
        }
        else{
            temp -> data = 0;
            carry =1;
        }
        temp = temp -> next; 
    }
    if(carry == 1) {
            Node* newnode = new Node(1);
            carry = 0;  
            head = reverseList(head);
            newnode -> next = head;
            return newnode;

        }
    head = reverseList(head);
    return head;
    }

int helper(Node* temp){
    if(temp == NULL) return 1;

    int carry = helper(temp -> next);
    temp -> data = temp -> data + carry;
    if(temp-> data < 10){
        return 0;
    }
    temp -> data = 0;
    return 1;

}

Node* addOne1(Node* head){

        int carry = helper(head);

        if(carry == 1) {
            Node* newnode = new Node(1);
            carry = 0;  
            head = reverseList(head);
            newnode -> next = head;
            return newnode;
        }
        return head;
} 


int main() {
    Node* head = nullptr;
    LinkedList ll;

    // Example: Number 129 (1 -> 2 -> 9)
    head = ll.append(head, 1);
    head = ll.append(head, 2);
    head = ll.append(head, 9);

    cout << "Original Number: ";
    ll.printList(head);

    head = addOne1(head);

    cout << "After Adding One: ";
    ll.printList(head);

    return 0;
}