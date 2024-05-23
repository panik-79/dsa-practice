// Diameter of a binary tree is the number of nodes in the longest path between any two nodes in a tree.

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

int heightOfBinaryTree(Node* root){
    int height = 0;
    if(root == NULL){
        return 0;
    }
    height = 1 + max(heightOfBinaryTree(root-> left), heightOfBinaryTree(root->right));
    return height;
}

// function to calculate the diameter of a binary tree
int diameterOfBinaryTree(Node* root){

    // base case
    // if the root is NULL, then the diameter of the binary tree is 0
    if(root == NULL){
        return 0;
    }


    // calculate the height of left subtree
    int leftHeight = heightOfBinaryTree(root -> left);
    // calculate the height of right subtree
    int rightHeight = heightOfBinaryTree(root -> right);
    
    // Option 1 : calculate the diameter of the left subtree -> both nodes which are at the maximum distance from the root node will be in the left subtree
    int leftDiameter = diameterOfBinaryTree(root -> left);

    // Option 2 : calculate the diameter of the right subtree -> both nodes which are at the maximum distance from the root node will be in the right subtree
    int rightDiameter = diameterOfBinaryTree(root -> right);

    // Option 3 : calculate the diameter of the binary tree -> both nodes which are at the maximum distance from the root node will be in the left subtree and right subtree
    // the diameter of the binary tree will be the maximum of the following three options
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
    // +1 is added to include the root node in the diameter of the binary tree.


}


int main(){

    Node* root = createBinaryTree();
    cout << "Height of Binary Tree : " << diameterOfBinaryTree(root) << endl;


}