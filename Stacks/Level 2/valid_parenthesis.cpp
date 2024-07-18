#include <bits/stdc++.h>
using namespace std;

bool ispar(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if (ch == '{' || ch == '(' || ch == '[') {
            st.push(ch);
        } else if (ch == '}') {
            if (!st.empty() && st.top() == '{') st.pop();
            else return false;
        } else if (ch == ')') {
            if (!st.empty() && st.top() == '(') st.pop();
             else return false;
        } else if (ch == ']') {
            if (!st.empty() && st.top() == '[') st.pop();
            else return false;
        }
    }

    return st.empty();
}

int main() {
    string str = "{([])}]";
    ispar(str) ? cout << "balanced" : cout << "not balanced" ;
    return 0;
}
