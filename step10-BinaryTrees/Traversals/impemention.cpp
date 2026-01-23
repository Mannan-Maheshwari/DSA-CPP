#include<bits/stdc++.h>
using namespace std;

// Class representing a Node in the Binary Tree
class Node {
public:
    int root;
    Node* left;
    Node* right;

    // Constructor to initialize a node with a given key
    Node(int val){
        val = root;
        left = nullptr;
        right = nullptr;
    }
    
};

// Class containing the logic for Binary Tree creation
class Tree {
public:
    Node* createBinaryTree() {
        Node* root = new Node(1);
        root -> left = new Node(3);
        root -> right = new Node(5);
        root -> right -> left = new Node(7);
        return root;
    }

};

// Driver code
int main(){
    Tree tree;
    Node* root = tree.createBinaryTree();
}