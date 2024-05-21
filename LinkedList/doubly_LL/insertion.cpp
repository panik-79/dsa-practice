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

        // with above code block, we have travered at required positions.
        // let's ay we needed to insert at idx = 2
        // using above loop, we have prevPtr at idx = 1 and nextPtr at idx = 2 (of existing LL)

        // now, we need to update links
        prevPtr -> next = newNode;
        newNode -> prev = prevPtr;
        nextPtr -> prev = newNode;
        newNode -> next = nextPtr;
    }
}


// considered as 0-based positioning of nodes
int main(){

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head -> next = second;
    second -> prev = head;
    second -> next = third;
    third -> prev = second;
    third -> next = NULL;

    Node* tail = third;

    // Node* head = NULL;
    // Node* tail = NULL;

    cout << lengthOfLL(head);
    printLL(head);

    insertAtHead(head, tail, 100);
    cout << lengthOfLL(head);
    printLL(head);

    insertAtTail(head, tail, 200);
    cout << lengthOfLL(head);
    printLL(head);

    // cout << "Head data : " << head ->data << endl;
    // cout << "Tail data : " << tail ->data << endl;

    // let's say we need to insert data = 500 at index = 2
    insertAtPosi(head, tail, 2, 500);
    cout << lengthOfLL(head);
    printLL(head);

    // invalid case
    insertAtPosi(head, tail, 10, 500);
    cout << lengthOfLL(head);
    printLL(head);

    insertAtPosi(head, tail, 5, 5);
    cout << lengthOfLL(head);
    printLL(head);
    
    // insertAtTail is called from insertAtPosi
    insertAtPosi(head, tail, 7, 1000);
    cout << lengthOfLL(head);
    printLL(head);

    return 0;

}