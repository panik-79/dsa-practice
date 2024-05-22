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


// logic :
// 1. if head is NULL, return
// 2. take two pointers prev and curr, initially prev = head and curr = head->next
// 3. iterate over the linked list
// 4. if curr->data == prev->data, then remove the curr node and update the next pointer of prev
// 5. else, update prev and curr
// 6. return
void removeDuplicatesFromSortedLL(Node* &head){
    if (head == NULL) {
        return;
    }
    
    Node* prev = head;
    Node* curr = head->next;

    while(curr != NULL){
        if(curr->data == prev->data){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}


// considering 0-based indexing for the position of the node
int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    cout << endl << "Original LL : ";
    printLL(head);
    cout << endl;

    cout << "After removing duplicates : ";
    removeDuplicatesFromSortedLL(head);
    printLL(head);
    return 0;
}