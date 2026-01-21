#include <bits/stdc++.h>
using namespace std;

// ListNode class representing a single digit in the linked list
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class to manage ListNode-level operations
class LinkedList {
public:
    // function to insert digit at the end
    ListNode* append(ListNode* head, int value) {
        ListNode* newnode = new ListNode(value);
        if (!head) {
            return newnode;
        }
        ListNode* current = head;
        while (current->next)
            current = current->next;
        current->next = newnode;
        return head;
    }

    // Function to print the list
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};

ListNode* reverseList(ListNode* ListNode) {
        ListNode* prev = nullptr;
        ListNode* current = ListNode;

        while (current) {
            ListNode* nextListNode = current->next;
            current->next = prev;
            prev = current;
            current = nextListNode;
        }
        return prev;
    }

ListNode* add2(ListNode* l1, ListNode* l2){
    ListNode* head1 = l1;
    ListNode* head2 = l2;
    ListNode* dummy = new ListNode();
    ListNode* temp = dummy;
    int carry =0;
    while(head1 != NULL || head2 != NULL){
        int sum = carry;
        if(head1 != NULL) {
            sum = sum + head1 -> data;
        }
        if(head2 != NULL){
            sum = sum + head2 -> data;
        }
        ListNode* newnode = new ListNode(sum%10);
        carry = sum /10;
        temp -> next = newnode;
        temp = temp -> next;
        if(head1 != NULL) {
            head1 = head1 -> next;
        }
        if(head2 != NULL){
            head2 = head2 -> next;
        }
        if(carry == 1)[
            newnode = new ListNode(1);
            temp -> next = newnode;
            
            
        ]

    }
    return dummy -> next;


}