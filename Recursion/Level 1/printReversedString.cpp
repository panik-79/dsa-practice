#include<iostream>
using namespace std;

void printRev(string s, int idx){

    if(idx == s.length()){
        return;
    }

    printRev(s, idx+1);
    cout << s[idx];
}

int main(){
    string s = "pujan" ;
    int index = 0;
    printRev(s, index);
}