#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int linearSearch(Node* head, int target, int index) {
    if (head == NULL) {
        return 0;
    }
    if (head->data == target) {
        return index;
    }
    return linearSearch(head->next, target, index + 1);
}

int main() {
    int n;
    cout<<"Enter the number of elements in the linked list: ";
    cin>>n;

    Node* head = NULL;
    Node* current = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cout<<"Enter element "<<i + 1<<": ";
        cin>>newNode->data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    int target;
    cout<<"Enter the number you want to find: ";
    cin>>target;

    int result = linearSearch(head, target, 0);

    if (result != 0) {
        cout<<"Element "<<target<<" found at index "<<result<<endl;
    } else {
        cout<<"Element "<<target<<" not found in the linked list."<<endl;
    }

    current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
