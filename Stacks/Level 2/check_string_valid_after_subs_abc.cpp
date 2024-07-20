// Problem link : https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    // Check initial constraints: start with 'a', end with 'c', and size is multiple of 3
    if(s[0] != 'a' || s[s.size() - 1] != 'c' || s.size() % 3 != 0){
        return false;
    }

    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == 'a') {
            st.push(ch);
        }
        else if(ch == 'b') {
            // Check if stack is empty before accessing top element
            if(st.empty() || st.top() != 'a') return false;
            st.push(ch);
        }
        else if(ch == 'c'){
            // Check if stack has at least 2 elements and follows 'a', 'b' sequence
            if(st.size() < 2) return false;
            char top1 = st.top(); st.pop();
            char top2 = st.top(); st.pop();
            if(top1 != 'b' || top2 != 'a') return false;
        }
    }

    // If the stack is empty, all sequences were valid
    return st.empty();
}

int main(){
    string str = "aabababccabccbc";
    bool checkValid = isValid(str);
    checkValid ? cout << "valid" : cout << "invalid" ;
}