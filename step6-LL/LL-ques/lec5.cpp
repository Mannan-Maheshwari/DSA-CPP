// Length of Loop in LL
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

//optimal approch
int lengthOfLoop(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
        int count =1;
        if(slow == fast ){
            Node* temp = slow -> next;
            while(temp != fast){
                temp = temp -> next;
                count++;
            }
            return count;
        }
    }
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Linking the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a loop from fifth to second
    fifth->next = second;

    // Getting the loop length
    int loopLength = lengthOfLoop(head);

    // Printing the result
    if (loopLength > 0) {
        cout << "Length of the loop: "
             << loopLength << endl;
    } else {
        cout << "No loop found in the linked list."
             << endl;
    }

    return 0;
}
