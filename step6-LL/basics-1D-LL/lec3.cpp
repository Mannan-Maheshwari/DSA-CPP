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

Node* deleteHead(Node* head){
    Node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = nullptr;
    return head;

}

Node* deletesomewhere(Node* head,int position){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    if (position == 1){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    Node* temp = head;
    int cnt =0;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == position){
            prev ->next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

int main() {
    // Initialize a vector with values for the linked list
    vector<int> arr = {12, 5, 8, 7};
    // Create a linked list with the values from the vector
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    // Call the deleteTail function to delete the last node
    head = deletesomewhere(head,3);
    // Print the linked list after deletion
    printLL(head);
}

