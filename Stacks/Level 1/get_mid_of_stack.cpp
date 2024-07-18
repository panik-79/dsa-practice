#include <bits/stdc++.h>
using namespace std;

int midOfStack(stack<int> &st, int &position)
{
    if (position == 1){
        int ans = st.top();
        // also deleting the mid element from stack !!
        st.pop();
        return ans;
    }

    int temp = st.top();
    st.pop();
    position--;
    int mid = midOfStack(st, position);

    st.push(temp);
    return mid;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int position = (st.size() % 2 == 0) ? st.size() / 2 : st.size() / 2 + 1;

    cout << "MIDDLE ELEMENT : " << midOfStack(st, position) << endl;

    cout << "UPDATED STACK : ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
