#include <iostream>
#include <stack>
using namespace std;

string reverse(string str)
{

    stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        st.push(str[i]);
    }

    string revStr = "";

    for (int i = 0; i < str.size(); i++)
    {
        revStr += st.top();
        st.pop();
    }

    return revStr;
}

int main()
{
    string str = "hello world";
    std::cout << "Reversed String : " << reverse(str);
}