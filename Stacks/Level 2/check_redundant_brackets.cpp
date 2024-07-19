#include<bits/stdc++.h>
using namespace std;

bool checkRedundancy(string s) {
    stack<char> st;
    for(int i = 0 ; i < s.size(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || 
        ch == '-' || ch == '*' || ch == '/' ){
            st.push(ch);
        } else if (ch == ')'){
            char stackTop = st.top();
            if(stackTop == '+' || stackTop == '-' || 
            stackTop == '*' || stackTop == '/'){
                while(st.top() != '(') st.pop();
                st.pop();
                continue;
            } else return true;
        }
    }
    return false;
}

int main(){
    // string s = "((a+b))";
    // string s = "(a+(b)+c)";
    string s = "(a+(b*c))";
    bool ans = checkRedundancy(s);
    if(ans) cout << "Redundant Brackets present";
    else cout << "Redundant Brackets absent";
}