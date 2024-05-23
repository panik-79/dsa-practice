#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(){
        cout << "Hi! I am an overridden default constructor" << endl;
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

Node* createBinaryTree(){
    cout << "Enter data : ";
    int data;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root -> left = createBinaryTree();
    cout << "Enter right child of " << data << endl;
    root -> right = createBinaryTree();
    return root;
}



// Height of a binary tree is the number of nodes in the longest path from the root node to the leaf node.
// function to calculate the height of a binary tree
int heightOfBinaryTree(Node* root){
    // base case
    int height = 0;
    if(root == NULL){
        return 0;
    }

    // recursive case -> calculating the height of left and right subtree and taking the maximum of both and adding 1 to it.
    // 1 is added to include the root node in the height.
    height = 1 + max(heightOfBinaryTree(root-> left), heightOfBinaryTree(root->right));
    return height;
}

int main(){

    Node* root = createBinaryTree();
    cout << "Height of Binary Tree : " << heightOfBinaryTree(root) << endl;


}