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

void reverseLLusingRecursion(Node* &head) {
    // Base case: if head is empty or only one node, it's already reversed
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Recursively reverse the rest of the list
    Node* newHead = head->next;
    reverseLLusingRecursion(newHead);

    // Reverse the current node's pointer
    head->next->next = head;
    head->next = nullptr;

    // Update head to the new head of the reversed list
    head = newHead;
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

    reverseLL(head);
    cout << "Reversed LL : ";
    printLL(head);
    cout << endl;

    reverseLLusingRecursion(head);
    cout << "Reversed back to original LL using Recursion : ";
    printLL(head);
    cout << endl;



    return 0;


}