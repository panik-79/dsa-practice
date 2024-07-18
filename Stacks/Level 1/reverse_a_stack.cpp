#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& st, int val) {
    // Base case: if stack is empty, push the value
    if (st.empty()) {
        st.push(val);
        return;
    }

    // Store the top element and pop it
    int temp = st.top();
    st.pop();

    // Recursive call to insert the value at the bottom
    insertAtBottom(st, val);

    // Push the stored top element back onto the stack
    st.push(temp);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int temp = st.top();
    st.pop();

    reverseStack(st);

    // Backtrack
    insertAtBottom(st, temp);
}

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "BEFORE : ";
    stack<int> tempStack = st;  // Create a temporary stack to print the original stack
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    reverseStack(st);

    cout << "AFTER : ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
