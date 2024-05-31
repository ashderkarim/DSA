#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() : root(NULL) {}

    Node* insert(Node* currentNode, int data) {
        if (currentNode == NULL) {
            return new Node(data);
        }

        if (data < currentNode->data) {
            currentNode->left = insert(currentNode->left, data);
        }
        else if (data > currentNode->data) {
            currentNode->right = insert(currentNode->right, data);
        }

        return currentNode;
    }

    Node* deleteNode(Node* currentNode, int data) {
        if (currentNode == NULL) {
            return currentNode;
        }

        if (data < currentNode->data) {
            currentNode->left = deleteNode(currentNode->left, data);
        }
        else if (data > currentNode->data) {
            currentNode->right = deleteNode(currentNode->right, data);
        }
        else {
            if (currentNode->left == NULL) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == NULL) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }

            Node* successor = findMin(currentNode->right);
            currentNode->data = successor->data;
            currentNode->right = deleteNode(currentNode->right, successor->data);
        }

        return currentNode;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* search(Node* currentNode, int data) {
        if (currentNode == NULL || currentNode->data == data) {
            return currentNode;
        }

        if (data < currentNode->data) {
            return search(currentNode->left, data);
        }
        else {
            return search(currentNode->right, data);
        }
    }

    void formTree(Node* currentNode) {
        if (currentNode != NULL) {
            cout<<currentNode->data<<" -> ";
            formTree(currentNode->left);
            formTree(currentNode->right);
        }
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void deleteNode(int data) {
        root = deleteNode(root, data);
        cout<<"\nNode with value "<<data<<" has been deleted from BST."<<endl;
    }

    Node* search(int data) {
        return search(root, data);
    }

    void display() {
        cout<<"\nBST traversal: ";
        formTree(root);
        cout<<"NULL."<<endl;
    }
};

int main() {
    int data;
    BinarySearchTree BST;

    BST.insert(4);
    BST.insert(1);
    BST.insert(3);
    BST.insert(2);
    BST.insert(7);
    BST.insert(9);
    BST.insert(10);

    system("cls");
    BST.display();
    system("pause");

    system("cls");
    cout<<"\nEnter node you want to delete: ";
    cin>>data;
    BST.deleteNode(data);
    BST.display();
    system("pause");

    system("cls");
    cout<<"\nEnter node you are looking for: ";
    cin>>data;

    Node* searchResult = BST.search(data);
    if (searchResult != NULL) {
        cout<<"\nNode with value "<<data<<" found in the BST."<<endl;
    }
    else {
        cout<<"\nNode with value "<<data<<" not found in the BST."<<endl;
    }
    system("pause");

    return 0;
}