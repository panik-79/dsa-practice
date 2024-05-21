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
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
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


int main(){

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head -> next = second;
    second -> prev = head;
    second -> next = third;
    third -> prev = second;
    third -> next = NULL;

    cout << lengthOfLL(head) << endl;
    printLL(head);

    
    return 0;

}