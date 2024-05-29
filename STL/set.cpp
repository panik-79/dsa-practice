// Set is a container that stores unique elements following a specific order.
// The elements in a set are sorted according to a specific criterion.
// The value of the elements in a set cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element.
// The elements in a set are immutable, i.e., the value of the elements cannot be modified once they are inserted into the set.
// The elements in a set are unique, i.e., the set does not allow duplicate elements.
// The elements in a set are sorted in ascending order by default.
// The time complexity of common operations on a set is as follows:
// Insertion: O(log n)
// Deletion: O(log n)
// Searching: O(log n)
// Traversal: O(n)

// The set class is defined in the <set> header file.

// It is implemented using a self-balancing binary search tree (Red-Black Tree) internally.
// It can also be implemented using a hash table or an AVL tree but the most common implementation is Red-Black Tree because it provides O(log n) time complexity for insertion, deletion, and searching operations and number of rotations are less as compared to AVL tree.

// Set operations:

// insert(val): Inserts an element into the set.
// erase(val): Removes an element from the set.
// find(val): Searches for an element in the set.
// clear(): Removes all elements from the set.
// size(): Returns the number of elements in the set.
// empty(): Returns true if the set is empty, false otherwise.
// begin(): Returns an iterator pointing to the first element in the set.
// end(): Returns an iterator pointing to the past-the-end element in the set.
// rbegin(): Returns a reverse iterator pointing to the last element in the set.
// rend(): Returns a reverse iterator pointing to the element preceding the first element in the set.
// lower_bound(val): Returns an iterator pointing to the first element that is not less than the given value.
// upper_bound(val): Returns an iterator pointing to the first element that is greater than the given value.
// equal_range(val): Returns a pair of iterators denoting the range of elements that are equal to the given value.
// count(val): Returns the number of elements equal to the given value in the set. (Since set stores unique elements, the count will be either 0 or 1) 

// use cases of set:
// To store unique elements in sorted order.
// To perform set operations like union, intersection, difference, etc.
// To efficiently search for an element in a collection of elements.
// To maintain a collection of elements with unique keys.

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
        // initialize a set of integers (by default, elements are sorted in ascending order)
        set<int> s;
        set<int> s1;


        // for descending order, use set<int, greater<int>> s;
    
        // insert elements into the set
        s.insert(10);
        s.insert(40);
        s.insert(20);
        s.insert(50);
        s.insert(30);

        s1.insert(10);
        s1.insert(40);
        s1.insert(20);
        s1.insert(100);
    
        // print the set
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    
        // check if an element is present in the set
        // find() returns an iterator to the element if found, otherwise, it returns an iterator to the past-the-end element
        if (s.find(30) != s.end()) {
            cout << "Element 30 is present in the set" << endl;
        } else {
            cout << "Element 30 is not present in the set" << endl;
        }
    
        // remove an element from the set
        s.erase(30);
    
        // print the set after removing an element
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;

        // check the size of the set
        cout << "Size of the set: " << s.size() << endl;

        // convert set to a vector
        vector<int> v(s.begin(), s.end());
        cout << "Vector elements: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        // delete all elements from the set
        s.clear();

        // check if the set is empty
        if (s.empty()) {
            cout << "Set is empty" << endl;
        } else {
            cout << "Set is not empty" << endl;
        }


        return 0;
}


// Types of sets in C++:

// set: It is a simple set that stores unique elements in sorted order. The elements are sorted in ascending order by default.
// multiset: It is a set that allows duplicate elements. The elements are stored in sorted order.
// unordered_set: It is a set that stores unique elements in an unordered manner. The elements are not sorted.
// unordered_multiset: It is a set that allows duplicate elements and stores them in an unordered manner. The elements are not sorted.

// The set and multiset are implemented using a self-balancing binary search tree (Red-Black Tree) internally, which provides O(log n) time complexity for insertion, deletion, and searching operations.
// The unordered_set and unordered_multiset are implemented using a hash table internally, which provides O(1) time complexity for insertion, deletion, and searching operations on average.
