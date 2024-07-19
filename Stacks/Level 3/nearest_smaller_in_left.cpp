#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerInLeft(vector<int> arr, int n){
    stack<int> st;
    vector<int > ans(n);
    for(int i = 0 ; i < n ; i++){
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
    vector<int> v = {6, 2, 4, 1, 3, 8, 9};
    int n = v.size();
    vector<int> result = nearestSmallerInLeft(v, n);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}


// NOTE : same logic as nearest greater in left, we just need to pop while (stack has bigger elements) instead of while(stack has smaller elements)