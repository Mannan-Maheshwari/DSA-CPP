#include<bits/stdc++.h>
using namespace std;

// Class representing a Node in the Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node with a given key
    // Node(int val){
    //     val = data;
    //     left = nullptr;
    //     right = nullptr;
    // }

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    
};

class Solution {
public:
    void preorder(Node* root, vector<int> &arr){
        if(root == nullptr){
            return;
        }
        arr.push_back(root -> data);
        preorder(root -> left, arr);    //recursively traverse
        preorder(root -> right, arr);
    }

    vector<int> preOrder(Node* root){
        // Create an empty vector to
        // store preorder traversal values
        vector<int> arr;
        // Call the preorder traversal function
        preorder(root, arr);
        // Return the resulting vector
        // containing preorder traversal values
        return arr;
    }
};

int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Create object of Solution class
    Solution sol;

    // Getting preorder traversal
    vector<int> result = sol.preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}