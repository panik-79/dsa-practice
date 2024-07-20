// Problem link : https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

#include<bits/stdc++.h>
using namespace std;

// O(n) time and O(n) space

vector<int> onlineStockSpan(int n, vector<int> v) {
    stack<int> st; // Stack to store indices
    vector<int> ans(n); // Vector to store the result (span values)
    
    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while the price at those indices is less than or equal to the current price
        while (!st.empty() && v[st.top()] <= v[i]) {
            st.pop();
        }
        
        // If the stack is empty, the span is i+1
        if (st.empty()) {
            ans[i] = i + 1;
        } else {
            // Otherwise, the span is the difference in indices
            ans[i] = i - st.top();
        }
        
        // Push the current index onto the stack
        st.push(i);
    }
    
    return ans;
}

int main(){
    int n = 7;
    vector<int>v =  {100, 80, 60, 70, 60, 75, 85};

    vector<int> res = onlineStockSpan(n, v);

    for(auto val : res){
        cout << val << " ";
    }
}