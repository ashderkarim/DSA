#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void BFS(Node* root, int key) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            if (q.empty()) {
                break;
            }
            q.push(NULL);
            cout<<" -> ";
            continue;
        }

        cout<<temp->data<<" -> ";

        if (temp->data == key) {
        	cout<<"NULL\n";
            cout<<"\nFound node: "<<key<<endl;
            break;
        }

        if (temp->left != NULL) {
            q.push(temp->left);
        }

        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
    
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->left->left = newNode(7);
    root->left->right->left->left->right = newNode(8);
    root->left->right->left->right = newNode(9);
    root->left->right->left->right->right = newNode(10);
    root->left->right->left->left->right->left = newNode(11);
    root->left->right->left->left->right->left->right = newNode(12);

    cout<<"Searching for node: ";
    BFS(root, 3);

    return 0;
}
