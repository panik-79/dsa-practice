// Logic :
// 1. break LL in two halve
// 2. reversse the econd half
// 3. start comparing both halves

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


Node* middleNode(Node* head) {

    // Checking for the empty list case
    if (head == nullptr) {
        cout << "No node present" << endl;
        return head; 
    }

    Node* slow;
    slow -> next = head;
    Node* fast = head;

    // Move fast two steps and slow one step until fast reaches the end of the list
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // slow now points to the middle node
    return slow;
}

void reverseLL(Node* &head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next; // store next node
        curr->next = prev; // reverse the current node's pointer
        prev = curr;       // move prev and curr one step forward
        curr = next;
    }

    head = prev; // update the head to the new front of the list
}


bool checkPalindrome(Node* p1, Node* p2){
    bool ans = true;
    while(p1 != NULL && p2 != NULL){
        if(p1->data != p2->data) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return ans;
}


// considering 0-based indexing for the position of the node
int main(){

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 10 ; i <= 30; i = i + 10){
        insertAtTail(head, tail, i);
    }
    for(int i = 30 ; i >= 10; i = i - 10){
        insertAtTail(head, tail, i);
    }
    cout << endl << "Original LL : ";
    printLL(head);
    cout << endl;

    Node* lastNodeOfFirstHalf = middleNode(head);
    Node* firstNodeOfSecondHalf =  lastNodeOfFirstHalf -> next;
    lastNodeOfFirstHalf -> next = NULL;

    reverseLL(firstNodeOfSecondHalf);

    cout << "Half 1 : ";
    printLL(head);
    cout << "Half 2 : ";
    printLL(firstNodeOfSecondHalf);

    // now we have two half LL with the second half reversed.

    bool isPalindrome = checkPalindrome(head, firstNodeOfSecondHalf);
    cout << endl;
    if(isPalindrome) cout << "Palindrome";
    else cout << "Not a Palindrome";

    return 0;
}