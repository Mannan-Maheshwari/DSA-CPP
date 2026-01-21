// Flattening of LL

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;

    // Constructors to initialize the
    // data, next, and child pointers
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

Node* merge(Node* t1, Node* t2){
    Node* dummynode =new Node(-1);
    Node* res = dummynode;

    while(t1 != NULL && t2 != NULL){
        if(t1 -> data > t2 -> data){
            res -> child = t2;
            res = t2;
            t2 = t2 -> child;
        }
        else{
            res -> child = t1;
            res = t1;
            t1 = t1 -> child;
        }
        res -> next = NULL;
    }
    if(t1){
        res -> child = t1;
    }
    else{
        res -> child = t2;
    }

    // Break the last node's
    // link to prevent cycles
    if(dummynode->child){
        dummynode->child->next = NULL;
    }

    return dummynode->child;
}

Node* Verticlelist(Node* head){
    if(head ==NULL || head -> next == NULL) return head;

    Node* mergehead = Verticlelist(head -> next);
    head = merge(head,mergehead);
    return head;
}

// Print the linked list by
// traversing through child pointers
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// Print the linked list
// in a grid-like structure
void printOriginalLinkedList(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;

        // If child exists, recursively
        // print it with indentation
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars
        // for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    // Create a linked list with child pointers
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    Node* flattened = Verticlelist(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}