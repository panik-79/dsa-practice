// Problem link : https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& M, int n) {
    // If there's only one person, there can't be a celebrity
    if (n == 1) return -1;

    // Stack to hold potential celebrity candidates
    stack<int> s;

    // Push all people onto the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Find a potential celebrity by comparing pairs of people
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        // If person a knows person b, then a can't be a celebrity
        if (M[a][b] == 1) {
            s.push(b);
        }
        // If person a doesn't know person b, then b can't be a celebrity
        else {
            s.push(a);
        }
    }

    // The last remaining person is a potential celebrity
    int top = s.top();

    // Check if the potential celebrity meets the criteria
    bool rowcheck = true;
    bool colcheck = true;

    // Check the row of the potential celebrity (should all be 0)
    for (int i = 0; i < n; i++) {
        if (M[top][i] != 0) {
            rowcheck = false;
            break;
        }
    }

    // Check the column of the potential celebrity (should all be 1 except self)
    for (int i = 0; i < n; i++) {
        if (top != i && M[i][top] != 1) {
            colcheck = false;
            break;
        }
    }

    // If both checks are satisfied, return the celebrity index
    if (rowcheck && colcheck) {
        return top;
    }

    // Otherwise, return -1 as there is no celebrity
    return -1;
}

int main() {
    // Test case 1
    vector<vector<int>> M1 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n1 = 3;
    cout << "Test case 1: ";
    int result1 = celebrity(M1, n1);
    if (result1 == -1) {
        cout << "No celebrity" << endl;
    } else {
        cout << "Celebrity is person " << result1 << endl;
    }

    // Test case 2
    vector<vector<int>> M2 = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {0, 0, 0, 0},
        {1, 1, 1, 0}
    };
    int n2 = 4;
    cout << "Test case 2: ";
    int result2 = celebrity(M2, n2);
    if (result2 == -1) {
        cout << "No celebrity" << endl;
    } else {
        cout << "Celebrity is person " << result2 << endl;
    }

    // Test case 3
    vector<vector<int>> M3 = {
        {0, 1},
        {1, 0}
    };
    int n3 = 2;
    cout << "Test case 3: ";
    int result3 = celebrity(M3, n3);
    if (result3 == -1) {
        cout << "No celebrity" << endl;
    } else {
        cout << "Celebrity is person " << result3 << endl;
    }

    return 0;
}

 
