// Problem link : https://www.geeksforgeeks.org/problems/decode-the-string2444/1

#include<bits/stdc++.h>
using namespace std;

bool isNum(char c){
    return c >= '0' && c <= '9';
}

bool isAlphabet(char c){
    return c >= 'a' && c <= 'z';
}

string decodedString(string s) {
    stack<string> st;
    string currentStr = "";
    int currentNum = 0;

    for (char ch : s) {
        if (isNum(ch)) {
            // Build the number (handling multiple digits)
            currentNum = currentNum * 10 + (ch - '0');
        } else if (ch == '[') {
            // Push the current string and reset
            st.push(currentStr);
            st.push(to_string(currentNum));  // Push the current number as a string
            currentStr = "";
            currentNum = 0;
        } else if (ch == ']') {
            // Pop the number and previous string
            string numStr = st.top(); st.pop();
            string prevStr = st.top(); st.pop();

            int repeatTimes = stoi(numStr);  // Convert the string number back to integer
            string expandedStr = "";

            // Repeat the current string 'repeatTimes' times
            for (int i = 0; i < repeatTimes; ++i) {
                expandedStr += currentStr;
            }

            // Append the expanded string to the previous string
            currentStr = prevStr + expandedStr;
        } else if (isAlphabet(ch)) {
            // Build the current string
            currentStr += ch;
        }
    }

    return currentStr;
}

int main(){

    string str = "3[b2[ca]]";
    cout << decodedString(str) << endl;

}