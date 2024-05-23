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

bool isBalanced(Node* root){

    // base case
    // if root is null, it is always balanced
    if(root == NULL) return true;

    int heightLeft = heightOfBinaryTree(root->left);
    int heightRight = heightOfBinaryTree(root->right);

    int differenceInHeight = abs(heightLeft - heightRight);

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    if(differenceInHeight <= 1 && leftAns && rightAns) return true;
    else return false;
}

int main(){
    Node* root = createBinaryTree();
    printTree(root);

    if(isBalanced(root)) cout << "Tree is balanced" << endl;
    else cout << "Tree is not balanced" << endl;
}