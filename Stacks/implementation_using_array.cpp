#include<iostream>
using namespace std;

class Stack{
    public:
        int* arr;  // Pointer to the array that holds stack elements
        int size;  // Maximum size of the stack
        int top;   // Index of the top element in the stack

        // Constructor to initialize the stack with a given size
        Stack(int size){
            arr = new int[size];  // Allocate memory for the stack
            this->size = size;    // Set the maximum size
            this->top = -1;       // Initialize top as -1 indicating the stack is empty
        }

        // Destructor to free the allocated memory
        ~Stack() {
            delete[] arr;  // Deallocate memory
        }

        // Method to push an element onto the stack
        void push(int data){
            if(top == size - 1){  // Check if the stack is full
                cout << "Could not push " << data << ", stack is full!" << endl;
            } else{
                top++;        // Increment top index
                arr[top] = data;  // Add the element to the stack
            }
        }

        // Method to pop the top element from the stack
        void pop(){
            if(top != -1){  // Check if the stack is not empty
                top--;      // Decrement top index
            } else {
                cout << "Stack is empty" << endl;
            }
        }

        // Method to get the top element of the stack
        int getTop(){
            if(top != -1){  // Check if the stack is not empty
                return arr[top];  // Return the top element
            }
            else {
                cout << "Element at top not found: ";
                return -1;  // Return -1 if the stack is empty
            }
        }

        // Method to get the current size of the stack
        int getSize(){
            return top + 1;  // Return the number of elements in the stack
        }

        // Method to check if the stack is empty
        bool isEmpty(){
            return top == -1;  // Return true if the stack is empty, false otherwise
        }

        // Method to clear the stack
        void clear(){
            top = -1;  // Set top to -1, effectively clearing the stack
        }

        // Method to peek at an element at a specific position from the top
        int peek(int pos){
            if(pos < 1 || pos > top + 1){  // Check if the position is valid
                cout << "Invalid position" << endl;
                return -1;  // Return -1 for invalid position
            } else {
                return arr[top - pos + 1];  // Return the element at the specified position
            }
        }

        // Method to search for an element in the stack
        int search(int data){
            for(int i = 0; i <= top; i++){
                if(arr[i] == data){  // Check if the element is found
                    return i;  // Return the position of the element
                }
            }
            return -1;  // Return -1 if the element is not found
        }

        // Method to print the stack elements
        void print(){
            if (isEmpty()) {  // Check if the stack is empty
                cout << "Stack is empty" << endl;
                return;
            }
            for(int i = 0; i <= top; i++){
                cout << arr[i] << " ";  // Print each element in the stack
            }
            cout << endl;
        }
};


int main(){
    Stack st(6);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top element: " << st.getTop() << endl;
    cout << "Stack contents: ";
    st.print();
    cout << "Element at position 2 from top: " << st.peek(2) << endl;
    cout << "Searching for element 20, found at position: " << st.search(20) << endl;
    st.pop();
    cout << "After pop, stack contents: ";
    st.print();
    cout << "Stack size: " << st.getSize() << endl;
    st.clear();
    cout << "After clear, stack contents: ";
    st.print();
    return 0;
}
