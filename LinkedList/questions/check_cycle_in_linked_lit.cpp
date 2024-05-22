#include<iostream>
using namespace std;

// Class to create a node
class Node{
    public:
    int data;
    Node* next;

    Node(){
        cout << "Hi! I am a constructor without data" << endl;
    }

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

// Function to print the linked list
void printLL(Node* head){
    Node* temp = head;
    if(temp == NULL){
        cout << "Empty LL" << endl;
        return;
    }
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "X" << endl;
}


void insertAtTail(Node* &head, Node* &tail ,int data){

    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp->next = newNode;
    tail = newNode;
}

// logic:
// 1. Initialize two pointers slow and fast to the head of the linked list
// 2. Move slow by one step and fast by two steps
// 3. If there is a cycle, slow and fast will meet at some point
// 4. If there is no cycle, fast will reach the end of the linked list
// Time complexity: O(n)
// Space complexity: O(1)
// logic:
bool hasCycle(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Function to return the starting node of the cycle
// If there is no cycle, return nullptr
// Floyd's Cycle Detection Algorithm
// Time complexity: O(n)
// Space complexity: O(1)
// logic: 
// 1. Find the intersection point of the two pointers
// 2. Move one pointer to the head and keep the other at the intersection point
// 3. Move both pointers one step at a time until they meet
// 4. The meeting point is the start of the cycle
Node* startOfCycle(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

// Function to remove the cycle from the linked list
// Time complexity: O(n)
// Space complexity: O(1)
// logic:
// 1. Find the starting node of the cycle
// 2. If there is no cycle, return
// 3. If there is a cycle, find the length of the cycle
// 4. Move one pointer to the head and the other to the kth node from the head
// 5. Move both pointers one step at a time until they meet
// 6. The meeting point is the start of the cycle
// 7. Move one pointer to the kth node from the head and the other to the start of the cycle
// 8. Move both pointers one step at a time until they meet
// 9. The meeting point is the end of the cycle
void removeCycle(Node* head) {
    Node* cycleStart = startOfCycle(head);
    if (cycleStart == nullptr) {
        return;
    }

    int cycleLength = 1;
    Node* temp = cycleStart->next;
    while (temp != cycleStart) {
        cycleLength++;
        temp = temp->next;
    }

    Node* slow = head;
    Node* fast = head;
    for (int i = 0; i < cycleLength; i++) {
        fast = fast->next;
    }

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* end = slow;
    while (end->next != slow) {
        end = end->next;
    }

    end->next = nullptr;
}

// considering 0-based indexing for the position of the node
int main(){

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 10 ; i <= 60 ; i = i + 10){
        insertAtTail(head, tail, i);
    }

    cout << endl << "Original LL : ";
    printLL(head);
    cout << endl;

    // Creating a cycle in the linked list
    tail->next = head->next->next;
    // printLL(head); //proof of cycle

    if (hasCycle(head)) {
        cout << "The linked list has a cycle" << endl;
    } else {
        cout << "The linked list does not have a cycle" << endl;
    }

    Node* cycleStart = startOfCycle(head);
    if (cycleStart != nullptr) {
        cout << "The cycle starts at node with data " << cycleStart->data << endl;
    } else {
        cout << "The linked list does not have a cycle" << endl;
    }

    removeCycle(head);
    cout << "Linked list after removing the cycle: ";
    printLL(head);

    if (hasCycle(head)) {
        cout << "The linked list has a cycle" << endl;
    } else {
        cout << "The linked list does not have a cycle" << endl;
    }


    return 0;
}