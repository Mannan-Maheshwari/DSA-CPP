// Delete the middle node of LL  

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

void PrintList(Node* head) // Function to print the LinkedList
{
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// optimum approch
Node* deletemiddle(Node* head){
    if (head == nullptr || head->next == nullptr) {
    delete head;
    return nullptr;
    }
    Node* slow = head -> next -> next;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    }
    Node* temp = slow -> next;    
    slow -> next = slow -> next -> next;
    free(temp);
    return head;
}



int main() {
    // Creating linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Printing original list
    cout << "Original Linked List: ";
    PrintList(head);

    // Deleting middle node
    head = deletemiddle(head);

    // Printing updated list
    cout << "Updated Linked List: ";
    PrintList(head);

    return 0;
}