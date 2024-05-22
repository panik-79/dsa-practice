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


void insertAtHead(Node* &head, Node* &tail ,int data){

    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
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

void addOne(Node* &head){
    Node* temp = head;
    while(temp->next != NULL){
        temp->data += 1;
        if(temp->data >= 10){
            temp->data = 0;
            temp = temp->next;
        }
        else{
            return;
        }
    }
    temp->data += 1;
    if(temp->data >= 10){
        temp->data = 0;
        Node* newNode = new Node(1);
        temp->next = newNode;
        return;
    }
}


Node* convertNumberToLL(int num){
    Node* head = NULL;
    Node* tail = NULL;

    while(num > 0){
        int digit = num % 10;
        insertAtHead(head, tail, digit);
        num = num / 10;
    }

    return head;
}

// considering 0-based indexing for the position of the node
int main(){

    // Node* head = NULL;
    // Node* tail = NULL;

    // for(int i = 1 ; i <= 3 ; i++){
    //     insertAtTail(head, tail, i);
    // }

    int num = 1234;
    Node* head = convertNumberToLL(num);

    cout << endl << "Original LL : ";
    printLL(head);
    cout << endl;

    reverseLL(head);
    cout << "Reversed LL : ";
    printLL(head);
    cout << endl;

    addOne(head);

    printLL(head);

    reverseLL(head);
    printLL(head);


    return 0;


}