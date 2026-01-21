// Sorting LL

#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int data1, ListNode* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }

    ListNode (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }

};

void PrintList(ListNode* head) // Function to print the LinkedList
{
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// brute force
ListNode* sortedll(ListNode* head){
    ListNode* temp =head;
    vector<int> arr;
    while(temp != NULL){
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    sort(arr.begin(),arr.end()); // we can use merge sort for a little better complexity
    
    temp = head;
    for(int i =0; i<arr.size(); i++){
        temp -> data = arr[i];
        temp = temp -> next;

    }
    return head;

}


// optimal approch
ListNode* middleNode(ListNode* head) {
    ListNode* fast = head -> next;
    ListNode* slow = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;

}
ListNode* mergetwosortedLL(ListNode* list1,ListNode* list2){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(list1 != nullptr && list2 != nullptr){
        if(list1 -> data <= list2 -> data){
            temp -> next = list1;
            list1 = list1 -> next;
        }
        else{
            temp -> next = list2;
            list2 = list2 -> next;
        }
        temp = temp -> next;
    }
    if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummy->next;
}
ListNode* sortedLL(ListNode* head){
    ListNode* temp = head;
    if (head == nullptr || head->next == nullptr) {
            return head;
        }
    ListNode* newhead= middleNode(temp);
    ListNode* right = newhead -> next;
    newhead -> next = nullptr;
    ListNode* left =temp;

    // Recursively sort both halves
        right = sortedLL(right);
        left = sortedLL(left);

    return mergetwosortedLL(right,left);

}

int main() {
    // Create linked list: 3 -> 2 -> 5 -> 4 -> 1
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(1);

    // Print original list
    cout << "Original Linked List: ";
    PrintList(head);

    // Sort the linked list
    head = sortedLL(head);

    // Print sorted list
    cout << "Sorted Linked List: ";
    PrintList(head);
    

    return 0;
}