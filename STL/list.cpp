// The list class is defined in the <list> header file.

// It is implemented as a doubly linked list internally.

// List operations:

// push_back(val): Adds an element to the end of the list.
// push_front(val): Adds an element to the front of the list.
// pop_back(): Removes the last element from the list.
// pop_front(): Removes the first element from the list.
// insert(pos, val): Inserts an element at the specified position in the list.
// erase(pos): Removes the element at the specified position in the list.
// clear(): Removes all elements from the list.
// size(): Returns the number of elements in the list.
// empty(): Returns true if the list is empty, false otherwise.
// front(): Returns a reference to the first element in the list.
// back(): Returns a reference to the last element in the list.
// begin(): Returns an iterator pointing to the first element in the list.
// end(): Returns an iterator pointing to the past-the-end element in the list.
// rbegin(): Returns a reverse iterator pointing to the last element in the list.
// rend(): Returns a reverse iterator pointing to the element preceding the first element in the list.

// Time complexity of list operations:

// Operation	Time complexity
// push_back	O(1)
// push_front	O(1)
// pop_back	    O(1)
// pop_front	O(1)
// insert	    O(1)
// erase	    O(1)
// clear	    O(n)
// size	        O(1)
// empty	    O(1)
// front	    O(1)
// back	        O(1)
// begin	    O(1)
// end	        O(1)
// rbegin	    O(1)
// rend	        O(1)


#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    // initialize a list
    list<int> l;

    // push elements to the back of the list
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);

    // push elements to the front of the list
    l.push_front(5);
    l.push_front(1);

    // print the list
    // auto keyword is used to automatically deduce the data type of the variable
    // range-based for loop is used to iterate over the elements of the list
    cout << "Original list:" << endl;
    for (auto x : l) {
        cout << x << " ";
    }

    // print the list using iterator
    // iterator is a pointer that points to an element in the list
    // begin() function returns an iterator pointing to the first element in the list
    // end() function returns an iterator pointing to the past-the-end element in the list
    cout << "Original list using iterator:" << endl;
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }

    // print the list in reverse order
    // rbegin() function returns a reverse iterator pointing to the last element in the list
    // rend() function returns a reverse iterator pointing to the element preceding the first element in the list
    cout << endl << "Reversed list:" << endl;
    for (auto it = l.rbegin(); it != l.rend(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    // get the size of the list
    cout << "Size of the list: " << l.size() << endl;

    // get the first element of the list
    cout << "First element of the list: " << l.front() << endl;

    // get the last element of the list
    cout << "Last element of the list: " << l.back() << endl;

    // pop elements from the back of the list
    l.pop_back();

    // pop elements from the front of the list
    l.pop_front();

    // print the list
    cout << "List after popping elements:" << endl;
    for (auto x : l) {
        cout << x << " ";
    }

    cout << endl;

    // insert an element at a specific position
    // advance function is used to advance the iterator by a specific number of positions
    // iterator is a pointer that points to an element in the list
    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 15);

    // print the list
    cout << "List after inserting an element:" << endl;
    for (auto x : l) {
        cout << x << " ";
    }

    cout << endl;

    // erase an element at a specific position
    it = l.begin();
    advance(it, 3);
    l.erase(it);

    // print the list
    cout << "List after erasing an element:" << endl;
    for (auto x : l) {
        cout << x << " ";
    }

    cout << endl;

    // clear the list
    l.clear();

    // check if the list is empty
    if (l.empty()) {
        cout << "List is empty" << endl;
    }

    return 0;

}