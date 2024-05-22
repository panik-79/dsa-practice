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

// Function to perform in-order traversal of a binary tree
void inOrderTraversal(Node* root){

    // Base case: if root is NULL, return
    if(root == NULL){
        return;
    }

    // Recursively traverse the left subtree
    inOrderTraversal(root->left);

    // Print the data of the current node
    cout << root->data << " ";

    // Recursively traverse the right subtree
    inOrderTraversal(root->right);
}

// Function to perform pre-order traversal of a binary tree
void preOrderTraversal(Node* root){

    // Base case: if root is NULL, return
    if(root == NULL){
        return;
    }

    // Print the data of the current node
    cout << root -> data << " ";

    // Recursively traverse the left subtree
    preOrderTraversal(root->left);

    // Recursively traverse the right subtree
    preOrderTraversal(root->right);
}

// Function to perform post-order traversal of a binary tree
void postOrderTraversal(Node* root){

    // Base case: if root is NULL, return
    if(root == NULL){
        return;
    }

    // Recursively traverse the left subtree
    postOrderTraversal(root->left);

    // Recursively traverse the right subtree
    postOrderTraversal(root->right);

    // Print the data of the current node
    cout << root -> data << " ";
}


int main(){

    Node* root = createTree();
    printTree(root);

    cout << "Inorder Traversal : " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "Preorder Traversal : " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal : " << endl;
    postOrderTraversal(root);


    return 0;
}

// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// Space Complexity: O(N), where N is the number of nodes in the binary tree. The space complexity is O(N) due to the recursive function calls and the space used by the call stack.

// In the above code, we have implemented the in-order, pre-order, and post-order traversals of a binary tree. The in-order traversal visits the left subtree, then the root node, and finally the right subtree. The pre-order traversal visits the root node, then the left subtree, and finally the right subtree. The post-order traversal visits the left subtree, then the right subtree, and finally the root node. We have used recursive functions to perform these traversals.


// Output:
// Enter data : 1
// Enter left child of 1
// Enter data : 2
// Enter left child of 2
// Enter data : 4
// Enter left child of 4
// Enter data : -1
// Enter right child of 4
// Enter data : -1
// Enter right child of 2
// Enter data : -1
// Enter right child of 1
// Enter data : 3
// Enter left child of 3
// Enter data : 5
// Enter left child of 5
// Enter data : -1
// Enter right child of 5
// Enter data : -1
// Enter right child of 3
// Enter data : -1
// 1 :  L 2 R 3
// 2 :  L 4
// 4 :
// 3 :  L 5
// 5 :
// Inorder Traversal :
// 4 2 1 5 3
// Preorder Traversal :
// 1 2 4 3 5
// Postorder Traversal :
// 4 2 5 3 1


