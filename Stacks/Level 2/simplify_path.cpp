// Problem link : https://leetcode.com/problems/simplify-path/description/

#include <bits/stdc++.h>
using namespace std;

// Function to simplify the given Unix-style path
string simplifyPath(string path) {
    stack<string> st;  // Stack to hold the path components
    int n = path.size();  // Length of the path string
    int i = 0;  // Index for traversing the path string
    string minPath = "";  // To accumulate current path component
    
    // Traverse the entire path string
    while (i < n) {
        char ch = path[i];
        
        if (ch == '/') {  // If current character is a slash
            if (minPath == "..") {  // Handle parent directory
                if (!st.empty()) st.pop();  // Go up one level if possible
            }
            else if (minPath != "" && minPath != ".") {  // Handle current directory or valid component
                st.push(minPath);  // Add valid directory to stack
            }            
            minPath = "";  // Reset minPath for the next component
        } else {
            minPath += ch;  // Accumulate characters for the current path component
        }
        i++;
    }

    // Handling the last part of the path if any
    if (minPath == "..") {
        if (!st.empty()) st.pop();  // Go up one level if possible
    } else if (minPath != "" && minPath != ".") {
        st.push(minPath);  // Add valid directory to stack
    }
    
    // Build the final simplified path
    string ans = st.empty() ? "/" : "";  // Start with a slash if the stack is empty
    while (!st.empty()) {
        ans = "/" + st.top() + ans;  // Construct the path from stack elements
        st.pop();  // Remove element from stack
    }
    
    return ans;  // Return the simplified path
}

int main() {
    // Test cases
    cout << "Test Case 1: " << simplifyPath("/a/./b/../../c/") << endl;  // Expected output: "/c"
    cout << "Test Case 2: " << simplifyPath("/home/../usr//bin/./") << endl;  // Expected output: "/usr/bin"
    cout << "Test Case 3: " << simplifyPath("/a/./b/..//c/") << endl;  // Expected output: "/a/c"

    return 0;
}



// Let's perform a dry run of the simplifyPath function on Test Case 3: "/a/./b/..//c/".
// Test Case 3: "/a/./b/..//c/"
// Initial Setup

//     Input Path: "/a/./b/..//c/"
//     Stack: []
//     Accumulated Component (minPath): ""
//     Index (i): 0

// Dry Run Steps

//     Iteration 1 (i = 0):
//         Character: '/'
//         Action: Skip over the slash; no change to minPath.
//         Stack: []
//         Accumulated Component (minPath): ""

//     Iteration 2 (i = 1):
//         Character: 'a'
//         Action: Accumulate 'a' in minPath.
//         Stack: []
//         Accumulated Component (minPath): "a"

//     Iteration 3 (i = 2):
//         Character: '/'
//         Action: Process accumulated minPath ("a"). Push "a" to stack.
//         Stack: ["a"]
//         Accumulated Component (minPath): ""

//     Iteration 4 (i = 3):
//         Character: '.'
//         Action: Accumulate '.' in minPath.
//         Stack: ["a"]
//         Accumulated Component (minPath): "."

//     Iteration 5 (i = 4):
//         Character: '/'
//         Action: Process accumulated minPath ("."). Since "." is ignored, no change to stack.
//         Stack: ["a"]
//         Accumulated Component (minPath): ""

//     Iteration 6 (i = 5):
//         Character: 'b'
//         Action: Accumulate 'b' in minPath.
//         Stack: ["a"]
//         Accumulated Component (minPath): "b"

//     Iteration 7 (i = 6):
//         Character: '/'
//         Action: Process accumulated minPath ("b"). Push "b" to stack.
//         Stack: ["a", "b"]
//         Accumulated Component (minPath): ""

//     Iteration 8 (i = 7):
//         Character: '..'
//         Action: Accumulate '..' in minPath.
//         Stack: ["a", "b"]
//         Accumulated Component (minPath): ".."

//     Iteration 9 (i = 8):
//         Character: '/'
//         Action: Process accumulated minPath (".."). Pop from stack, removing "b".
//         Stack: ["a"]
//         Accumulated Component (minPath): ""

//     Iteration 10 (i = 9):
//         Character: '/'
//         Action: Skip over the extra slashes; no change to minPath.
//         Stack: ["a"]
//         Accumulated Component (minPath): ""

//     Iteration 11 (i = 10):
//         Character: 'c'
//         Action: Accumulate 'c' in minPath.
//         Stack: ["a"]
//         Accumulated Component (minPath): "c"

//     Iteration 12 (i = 11):
//         Character: '/'
//         Action: Process accumulated minPath ("c"). Push "c" to stack.
//         Stack: ["a", "c"]
//         Accumulated Component (minPath): ""

// After Loop Completion

//     Remaining Path Component: None (processed during the loop)
//     Final Stack: ["a", "c"]

// Building Final Path

//     Initialize Result (ans): Empty
//     While Loop to Build Path:
//         First Iteration:
//             Stack: ["a"]
//             Append: "/c"
//             Result: "/c"
//         Second Iteration:
//             Stack: []
//             Append: "/a"
//             Result: "/a/c"

// Final Result

//     Simplified Path: "/a/c"