#include <iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* left;
    Node* right;

    Node(){
        cout << "Hi! I am a constructor without data" << endl;
    }


    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

};

void printTree(Node* root){

    // base case
    // if root is NULL, return
    if(root == NULL){
        return;
    }

    // print the root node
    cout << root -> data << " : ";

    // print the left and right child of the root node if they exist
    if(root -> left != NULL){
        cout << " L " << root -> left -> data;
    }
    if(root -> right != NULL){
        cout << " R " << root -> right -> data;
    }

    cout << endl;

    // print left subtree
    printTree(root -> left);

    // print right subtree 
    printTree(root -> right);
}


Node* createTree(){

    // enter the data of the root node
    cout << "Enter data : ";
    int data;
    cin >> data;

    // if data is -1, return NULL ->  which means no node is created
    if(data == -1){
        return NULL;
    }

    // create a new node with the data
    Node* root = new Node(data);

    // ask for the left child of the root node
    cout << "Enter left child of " << data << endl;
    // create the left child of the root node
    root -> left = createTree();

    // ask for the right child of the root node
    cout << "Enter right child of " << data << endl;
    // create the right child of the root node
    root -> right = createTree();

    return root;
}


int main(){

    Node* root = createTree();
    printTree(root);

    return 0;
}