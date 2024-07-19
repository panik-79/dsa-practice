#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> arr, int n){
    stack<int> st;
    vector<int > ans(n);
    for(int i = n-1 ; i >= 0 ; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
            st.push(arr[i]);
            continue;
        } else {
            ans[i] = st.top();
            st.push(arr[i]);
            continue;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1, 3, 2, 4};
    int n = v.size();
    vector<int> result = nextLargerElement(v, n);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}







// Next Greater Element 2 : https://www.geeksforgeeks.org/problems/next-greater-element-2/1
// (circular array)

// vector<int> nextGreaterElement(int N, vector<int>& arr) {
//     // code here
//     stack<int> st;
//     vector<int> ans(N, -1);
//     for (int i = 2 * N - 1; i >= 0; i--) {
//         while (!st.empty() && st.top() <= arr[i % N]) {
//             st.pop();
//         }

//         if (i < N) {
//             if (!st.empty()) {
//                 ans[i] = st.top();
//             }
//         }

//         st.push(arr[i % N]);
//     }

//     return ans;
// }