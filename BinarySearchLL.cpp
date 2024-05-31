#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int binarySearch(Node* head, int target) {
    int left = 0;
    int right = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        right++;
    }
    right--;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        if (temp->data == target) {
            return mid;
        }
        if (temp->data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int n;
    cout<<"Enter the number of elements in the sorted linked list: ";
    cin>>n;

    Node* head = NULL;
    Node* current = NULL;

    cout<<"Enter the sorted elements in ascending order:\n";
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cin >> newNode->data;
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

    int result = binarySearch(head, target);

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
