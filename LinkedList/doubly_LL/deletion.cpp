#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        cout << "Hi! I am a constructor without data" << endl;
    }

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL; 
    }
};

// Function to print the linked list
void printLL(Node* head){

    if(head == NULL){
        cout << endl;
        cout << "Empty LL" << endl;
        return;
    }

    Node* temp = head;
    cout << endl;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
    return;
}

// Function to find the length of the linked list
int lengthOfLL(Node* head){
    Node* temp = head;
    int nodeCount = 0;
    while(temp != NULL){
        nodeCount++;
        temp = temp -> next;
    }
    return nodeCount;
}

// Function to insert a node at the head of the linked list
void insertAtHead(Node* &head, Node* &tail, int data){

    Node* newNode = new Node(data);

    // handling the empty LL case
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node* &head, Node* &tail, int data){

    Node* newNode = new Node(data);

    // handling the empty LL case
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        newNode -> prev = temp;
        temp -> next = newNode;
        tail = newNode;
        return;
    }
}

// Function to insert a node at a specific position in the linked list
void insertAtPosi(Node* &head, Node* &tail, int idx, int data){

    // handling invalid positions
    if(idx < 0 || idx > lengthOfLL(head)){
        cout << "Invalid position to insert data" << endl;
        return;
    }

    // handling first position
    else if(idx == 0){
        insertAtHead(head, tail, data);
        return;
    }

    // handling last position
    else if(idx == lengthOfLL(head)){
        insertAtTail(head, tail, data);
        return;
    }

    // insertion of a node somewhere in the middle of doubly LL
    else{
        Node* newNode  = new Node(data);
        Node* prevPtr = head;
        Node* nextPtr = head -> next;

        int i = 0;
        while(i < idx - 1){
            prevPtr = prevPtr -> next;
            nextPtr = nextPtr -> next;
            i++;
        }

        // with above code block, we have traversed to the required positions.
        // let's say we needed to insert at idx = 2
        // using the above loop, we have prevPtr at idx = 1 and nextPtr at idx = 2 (of existing LL)

        // now, we need to update links
        prevPtr -> next = newNode;
        newNode -> prev = prevPtr;
        nextPtr -> prev = newNode;
        newNode -> next = nextPtr;
    }
}

// Function to delete a node from the head of the linked list
void deleteFromHead(Node* &head){

    // handling the case of an empty LL
    if(head == NULL){
        cout << "No node present to delete" << endl ;
        return;
    }

    // single node case also needs to be handled separately
    else if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    head = head -> next ;
    head -> prev = NULL;
    return;
}

// Function to delete a node from the tail of the linked list
void deleteFromTail(Node* &head, Node* &tail){

    // handling the case of an empty LL
    if(head == NULL){
        cout << "No node present to delete" << endl ;
        return;
    }

    // single node case also needs to be handled separately
    else if(head -> next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    else{
        // directly using tail to delete
        Node* temp = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        delete temp;
    }
}

// Function to delete a node from a specific position in the linked list
void deleteFromPosi(Node* &head, Node* &tail, int idx){

    // handling invalid positions
    if(idx < 0 || idx >= lengthOfLL(head)){
        cout << "Invalid position to delete data" << endl;
        return;
    }

    // handling first position
    else if(idx == 0){
        deleteFromHead(head);
        return;
    }

    // handling last position
    else if(idx == lengthOfLL(head) - 1){
        deleteFromTail(head, tail);
        return;
    }

    // deletion of a node somewhere in the middle of doubly LL
    else{
        Node* temp = head;
        int i = 0;
        while(i < idx){
            temp = temp -> next;
            i++;
        }

        // with the above code block, we have traversed to the required positions.
        // let's say we needed to delete at idx = 2
        // using the above loop, we have temp at idx = 2 (of existing LL)

        // now, we need to update links
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        delete temp;
    }
}

// considered as 0-based positioning of nodes
int main(){

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 10 ; i <= 50 ; i = i + 10){
        insertAtTail(head, tail, i);
    }

    printLL(head);
    cout << lengthOfLL(head);

    // deleteFromHead(head);
    // printLL(head);
    // cout << lengthOfLL(head);

    // deleteFromTail(head, tail);
    // printLL(head);
    // cout << lengthOfLL(head);   
    // deleteFromTail(head, tail);
    // printLL(head);
    // cout << lengthOfLL(head);   
    // deleteFromTail(head, tail);
    // printLL(head);
    // cout << lengthOfLL(head);   

    // deleteFromHead(head);
    // printLL(head);
    // cout << lengthOfLL(head);   
    // deleteFromHead(head);
    // printLL(head);
    // cout << lengthOfLL(head);   

    deleteFromPosi(head, tail, 2);
    printLL(head);
    cout << lengthOfLL(head);

    return 0;
}