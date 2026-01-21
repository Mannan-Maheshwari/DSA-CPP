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

// void printLL(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }   FOR TRAVERSAL AND PRINTING OF LINK LIST

int main(){
    vector<int> arr={2,5,8,7};
    Node* y= new Node(arr[3]);
    cout<<y<<'\n'; // returns the memory value
    cout<<y->data<<'\n'; // returns the data stored at that memory point

}
        
    
