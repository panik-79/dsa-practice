#include<iostream>
using namespace std;

void printSubseq(string s, string subseq, int idx){

    if(idx == s.length()){
        cout << subseq << endl;
        return;
    }

    char currChar = s[idx];
    // including the current char
    printSubseq(s, subseq + currChar, idx+1);
    // not including the current char
    printSubseq(s, subseq, idx+1);

}

int main(){
    string s = "abc";
    printSubseq(s, "", 0);
}

// T.C. : O(n * 2^n)