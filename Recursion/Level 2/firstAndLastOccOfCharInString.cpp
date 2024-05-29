#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastOcc(string s, char ch,  pair<int, int> ans, int idx){

    if(idx == s.length()) return ans;
    
    char currChar = s[idx];
    if(currChar == ch){
        if(ans.first == -1){
            ans.first = idx;
        }else{
            ans.second = idx;
        }
    }

    return firstAndLastOcc(s, ch, ans, idx+1);
}

int main(){
    string s = "dcabaacdaefaah";
    char ch = 'a';
    int first = -1;
    int last = -1;
    pair<int, int> p = make_pair(first, last);

    pair<int, int> ans = firstAndLastOcc(s, ch, p, 0);
    
    cout << "First Occurence : " << ans.first << endl;
    cout << "Last Occurence : " << ans.second << endl;
}