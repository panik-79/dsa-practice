#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<long long> st;
    vector<long long > ans(n);
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
    vector<long long> v = {1, 3, 2, 4};
    int n = v.size();
    vector<long long> result = nextLargerElement(v, n);

    for (long long val : result) {
        cout << val << " ";
    }
    cout << endl;
}