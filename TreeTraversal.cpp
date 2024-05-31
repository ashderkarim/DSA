#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

void displayTree(Node* root) {
    if (root != NULL) {
        cout<<root->data<<" ";
        displayTree(root->left);
        displayTree(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int choice;

    cout<<"Choose operation:\n";
    cout<<"1. Display entire tree\n";
    cout<<"2. Preorder traversal\n";
    cout<<"3. Inorder traversal\n";
    cout<<"4. Postorder traversal\n";
    cout<<"Enter your choice (1, 2, 3, or 4): ";
    cin>>choice;

    switch (choice) {
        case 1:
            cout<<"Displaying entire tree: ";
            displayTree(root);
            break;
        case 2:
            cout<<"Preorder Traversal: ";
            preorderTraversal(root);
            break;
        case 3:
            cout<<"Inorder Traversal: ";
            inorderTraversal(root);
            break;
        case 4:
            cout<<"Postorder Traversal: ";
            postorderTraversal(root);
            break;
        default:
            cout<<"Invalid choice.";
    }

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
