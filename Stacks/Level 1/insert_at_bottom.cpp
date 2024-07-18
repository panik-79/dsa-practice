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

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int val = 500;
    insertAtBottom(st, val);

    // Printing the stack to verify the value is at the bottom
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
