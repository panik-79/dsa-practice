// Pair is a simple container defined in <utility> header consisting of two data elements or objects (first and second) 
// It is implemented as a class template that can store two values of different data types
// Pair provides a way to store two heterogeneous objects as a single unit

// pair class template

// class pair {
// public:
//     T1 first;
//     T2 second;
// };

// Here, T1 and T2 are the types of first and second elements, respectively
// The first element is referenced as 'first' and the second element is referenced as 'second'


#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    // initialize a pair
    pair<int, char> p;

    // assign values to pair
    p.first = 10;
    p.second = 'B';
    cout << p.first << " " << p.second << endl;

    // Another way to initialize a pair by passing values in constructor (copy constructor is called here)
    pair<int, char> p2(p);
    cout << p2.first << " " << p2.second << endl;

    // Another way to initialize a pair using make_pair function
    pair<int, char> p3 = make_pair(100, 'A');
    cout << p3.first << " " << p3.second << endl;

    // Pair of pairs (nested pairs) 
    pair<pair<int, int>, string> car;
    car.first.first = 10;
    car.first.second = 20;
    car.second = "Audi";
    cout << car.first.first << " " << car.first.second << " " << car.second << endl;

    // pair of pairs using make_pair
    pair<pair<int, int>, string> car2 = make_pair(make_pair(10, 20), "Audi");
    cout << car2.first.first << " " << car2.first.second << " " << car2.second << endl;

    return 0;
}