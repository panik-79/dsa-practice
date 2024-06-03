#include <iostream>
#include <vector>
using namespace std;

void solve(string s, string permutation, vector<string> &ans){
    
    if(s.length() == 0){
        ans.push_back(permutation);
        return;
    }
    
    for(int i = 0 ; i < s.length(); i++){
        char currChar = s[i];
        string newStr = s.substr(0, i) + s.substr(i+1);
        solve(newStr, permutation + currChar, ans);
    }
    
}

vector<string> permutation(string s)
{
    string permutation = "";
    vector<string> ans;
    solve(s, permutation, ans);
    return ans;
}

int main(){
    string s = "abc";
    vector<string> v = permutation(s);
    for(auto x : v) cout << x << " ";
    return 0;
}
