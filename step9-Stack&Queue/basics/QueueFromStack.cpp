#include<bits/stdc++.h>
using namespace std;

class StackQueue {
    // stack
    stack<int> st1;
    stack<int> st2;

public:
    void push(int x){

        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop(){

        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }

        int n = st2.top();
        st2.pop();
        return n;

    }

    int top(){

        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }

        return st2.top();
    }

    bool isEmpty(){
        return st1.empty();
    }

};

int main() {
    StackQueue q;
    
    // List of commands
    vector<string> commands = {"StackQueue", "push", "push", 
                               "pop", "peek", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "StackQueue") {
            cout << "null ";
        }
    }
    
    return 0;
}