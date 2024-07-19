#include<bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterInLeft(vector<int> arr, int n){
    stack<int> st;
    vector<int > ans(n);
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> v = {6, 2, 4, 1, 3, 8, 9};
    int n = v.size();
    vector<int> result = nearestGreaterInLeft(v, n);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

// NOTE : same logic as nearest greater in right (next greater element), we just need to revert the loop from n-1 -> 0 to 0 -> n-1