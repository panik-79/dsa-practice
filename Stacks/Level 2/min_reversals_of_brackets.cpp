// Problem Link : https://www.geeksforgeeks.org/problems/count-the-reversals0401/1

#include<bits/stdc++.h>
using namespace std;

int countRev (string str){

    // string with odd length can never be balanced ( so we return -1)
    if(str.size() % 2) return -1;

    // basic logic to nullify already balanced pairs of paranthesis
    stack<char> st;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (ch == '{') {
            st.push(ch);
        } else {
            if (!st.empty() && st.top() == '{') st.pop();
            else st.push(ch);
        }
    }
    // after the above code, stack has brackets (even #)
    
    int count = 0;
    
    // picking top 2 elements from stack and process accordingly 
    while(!st.empty()){
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();
        
        if(c1 == '{' && c2 == '{') count += 1;
        else if(c1 == '}' && c2 == '}') count += 1;
        else if(c1 == '{' && c2 == '}') count += 2;
    }
    
    return count;
    
}

int main(){
    // string str = "{{}{{{}{{}}{{"
    string str = "}{{}}{{{";
    cout << countRev(str) << endl;
}