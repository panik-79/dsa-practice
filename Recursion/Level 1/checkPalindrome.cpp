#include<iostream>
using namespace std;

bool checkPalindrome(string s, int n, int idx){

    if(idx > n/2) return true;

    if(s[idx] == s[n-idx-1]){
        checkPalindrome(s, n, idx+1);
    }
    else return false;


}

int main(){
    string s;
    s = "racecar";
    int len = s.length();
    bool isPalindrome = checkPalindrome(s, len, 0);

    if(isPalindrome) cout << "Palindrome";
    else cout << "Not a Palindrome";
}