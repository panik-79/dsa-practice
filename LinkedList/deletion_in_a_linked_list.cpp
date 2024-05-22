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
}

// Function to find the length of the linked list
int lengthOfLL(Node* head){
    Node*temp = head ;
    int nodeCount = 0;
    while(temp != NULL){
        nodeCount++;
        temp = temp -> next;
    }

    return nodeCount;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);

    // handling the edge-case of empty linked-list
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    // if linked-list is not empty, then, 
    newNode->next = head;
    head = newNode;
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

void insertAtPosi(Node* &head, Node* &tail ,int posi, int data){

    // if the position is 0, then, we insert the new node at the head of the linked list
    if(posi == 0){
        insertAtHead(head, tail, data);
    }

    // if the position is negative, then, we cannot insert the new node at that position
    else if(posi<0){
        cout << "Invalid position" << endl;
    }

    // if the position is the length of the linked list, then, we insert the new node at the end of the linked list
    else if(posi == lengthOfLL(head)){
        insertAtTail(head, tail, data);
    }

    // if the position is greater than the length of the linked list, then, we cannot insert the new node at that position
    else if(posi > lengthOfLL(head)){
        cout << "Invalid position" << endl;
    }

    // if the position is neither 0, nor negative, nor equal to the length of the linked list, nor greater than the length of the linked list, then we need to insert somewhere in between
    else {
        Node* newNode = new Node(data);
        Node* temp = head;

        // traversing to the node just before the position where we want to insert the new node
        int i = 0;
        while(i < posi-1){
            temp = temp -> next;
            i++;
        }
        // updating the next pointer of the new node to the node at the position
        // now, both the newNode and the temp are pointing to the same node (i.e., the node at the position where we want to insert the new node)
        newNode->next = temp->next;
        // updating the next pointer of the node just before the new node
        // now temp is pointing to newNode and newNode is pointing to the node at the position
        // thereby, we have successfully inserted the new node at the desired position
        temp->next = newNode;
    }

}


// deleting a node from beginning of the linked list
void deleteFromHead(Node* &head, Node* &tail){
    if(lengthOfLL(head) == 0){
        cout << "No node present in LL";
    }
    else{
        // simply move head ptr. to next node.
        head = head -> next;
    }
}

void deleteFromTail(Node* &head, Node* &tail){
    if(lengthOfLL(head) == 0){
        cout << "No node present in LL";
    }
    else{
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
    }
}

void deleteFromPos(Node* &head, Node* &tail, int posi){

    if(posi < 0 || posi > lengthOfLL(head)-1){
        cout << "Invalid position to delete a node" << endl;
    }

    else if(posi == 0 && head!=NULL){
        deleteFromHead(head, tail);
    }

    else if(posi == lengthOfLL(head)-1){
        deleteFromTail(head, tail);
    }

    else{
        // deletion from somewhere in between
        int i = 0;
        Node* prev = head;
        Node* curr = head -> next ;

        // agar meri posi 3 hai to mujhe 2 tak jana hai
        // curr jayega 3 tak prev jayega 2 tak

        while(i < posi-1){
            prev = prev -> next;
            curr = curr -> next;
            i++;
        }

        // breaking the link between prev and curr .
        // 3 delete karna tha , therefore, i broke the link between prev(2) and curr(3)
        // and added the link between prev(2) and next of curr(4)
        prev -> next = curr -> next;
    }

}

// considering 0-based indexing for the position of the node
int main(){

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    Node* tail = third;

    head -> next = second;
    second -> next = third;
    third -> next = NULL;

    // insertAtTail(head, tail, 40);
    // insertAtTail(head, tail, 50);

    deleteFromTail(head, tail);
    deleteFromTail(head, tail);

    printLL(head);
    cout << endl;
    cout << "Length of the linked list is: " << lengthOfLL(head) << endl;

    // deleteFromHead(head, tail);
    // printLL(head);
    // cout << endl;
    // cout << "Length of the linked list is: " << lengthOfLL(head) << endl;

    // deleteFromTail(head, tail);
    // printLL(head);
    // cout << endl;
    // cout << "Length of the linked list is: " << lengthOfLL(head) << endl;

    // check head data
    cout << "Head data: " << head -> data << endl;
    cout << "Tail data: " << tail -> data << endl;

    deleteFromPos(head, tail, 0);
    printLL(head);
    cout << endl;
    cout << "Length of the linked list is: " << lengthOfLL(head) << endl;

    // check head data after deletion of single node
    cout << "Head data: " << head -> data << endl;
    cout << "Tail data: " << tail -> data << endl;


    return 0;


}