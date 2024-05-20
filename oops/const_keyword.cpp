// const keyword in c++ is used to declare a variable, a function or a object as constant/immutable.
// Constant is an entity that doesn't change.
// if modification is attempted, compiler will throw an error.

// consts are stored in read-only memory (ROM) and are not stored in stack or heap memory.


#include<iostream>
using namespace std;

int main(){

    const int y = 20;
    // y = 30; // error: assignment of read-only variable 'y'
    cout<<y<<endl;

    // const int z; // error: uninitialized const 'z'
    // cout<<z<<endl;


    // const with pointers  
    int *x = new int(10);
    cout<<*x<<endl;
    delete x;
    int b = 5;
    x = &b;
    cout<<*x<<endl;

    const int *p = new int(10);
    
    



    return 0;
}