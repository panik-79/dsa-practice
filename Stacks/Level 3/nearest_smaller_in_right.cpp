#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerInRight(vector<int> arr, int n){
    stack<int> st;
    vector<int > ans(n);
    for(int i = n-1 ; i >= 0 ; i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> v = {6, 2, 4, 1, 3, 8, 9, 6};
    int n = v.size();
    vector<int> result = nearestSmallerInRight(v, n);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}
