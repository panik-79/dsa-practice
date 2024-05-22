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


int middleNode(Node* head) {

    // Checking for the empty list case
    if (head == nullptr) {
        cout << "No node present" << endl;
        return -1; 
    }

    Node* slow = head;
    Node* fast = head;

    // Move fast two steps and slow one step until fast reaches the end of the list
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // slow now points to the middle node
    return slow->data;
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

    cout << "Data at the middle node : " << middleNode(head) << endl;

    return 0;
}