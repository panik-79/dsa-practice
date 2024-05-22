#include<iostream>
#include<queue>
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
    if(root == NULL){
        return;
    }
    cout << root -> data << " : ";
    if(root -> left != NULL){
        cout << " L " << root -> left -> data;
    }
    if(root -> right != NULL){
        cout << " R " << root -> right -> data;
    }

    cout << endl;
    printTree(root -> left);
    printTree(root -> right);
}

Node* createTree(){
    cout << "Enter data : ";
    int data;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root -> left = createTree();
    cout << "Enter right child of " << data << endl;
    root -> right = createTree();
    return root;
}


// Perform level order traversal of a binary tree
// 1. If the root is NULL, return
// 2. Create an empty queue
// 3. Enqueue the root node
// 4. Repeat the following steps until the queue is empty:
//    - Dequeue a node from the queue
//    - Print the data of the dequeued node
//    - Enqueue its left child if it exists
//    - Enqueue its right child if it exists
// 5. End

void levelOrderTraversal(Node* root){
    // if root is NULL, return
    if(root == NULL){
        return;
    }

    // create a queue of Node* type, it will store the address of the nodes of the tree
    // we are using queue because we want to print the nodes level by level and queue follows FIFO order 
    // i.e. first in first out order which is required for level order traversal
    queue<Node*> q;

    // push the root node into the queue
    q.push(root);

    // iterate over the queue until it is empty
    while(!q.empty()){
        // pop the front element of the queue
        Node* curr = q.front();
        q.pop();

        // print the data of the current node
        cout << curr -> data << " ";

        // if left child of the current node exists, push it into the queue
        if(curr -> left != NULL){
            q.push(curr -> left);
        }

        // if right child of the current node exists, push it into the queue
        if(curr -> right != NULL){
            q.push(curr -> right);
        }
    }
}


int main(){

    Node* root = createTree();
    printTree(root);

    cout << "Level order traversal : " ;
    levelOrderTraversal(root);

    return 0;
}