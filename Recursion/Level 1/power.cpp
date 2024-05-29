#include<iostream>
using namespace std;

// pow calculates x^n in O(n)
int pow(int x, int n){
    if(x == 0) return 0;
    if(n == 0) return 1;

    return x*pow(x, n-1);
}

// power calculates x^n in O(log n)
int power(int x, int n){
    if(n == 0) return 1;
    if(x == 0) return 0;

    int half = power(x, n/2);

    if(n % 2 == 0){
        return half*half;
    } else{
        return half*half*x;
    }
}

int main(){
    int x = 5;
    int n = 5;
    cout << pow(x, n) << endl;
    cout << power(x, n) << endl;
}