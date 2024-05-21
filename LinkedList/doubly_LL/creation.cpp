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

int main(){

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head -> next = second;
    second -> prev = head;
    second -> next = third;
    third -> prev = second;
    third -> next = NULL;

    
    return 0;

}