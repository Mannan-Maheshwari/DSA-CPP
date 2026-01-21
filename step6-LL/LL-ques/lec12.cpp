// Find intersection of Two Linked Lists

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int data1, ListNode* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

void insertNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;

    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
    }

    return a;
}

int main() {
    // List 1: 1->3->1->2->4
    ListNode* head = nullptr;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    ListNode* head1 = head;

    // Make intersection at node with value 2
    head = head->next->next->next;

    // List 2: 3->2->4 (intersects)
    ListNode* headSec = nullptr;
    insertNode(headSec, 3);
    ListNode* head2 = headSec;
    headSec->next = head;

    cout << "List1: "; printList(head1);
    cout << "List2: "; printList(head2);

    ListNode* answerNode = getIntersectionNode(head1, head2);
    if (answerNode == nullptr)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->data << endl;

    return 0;
}
