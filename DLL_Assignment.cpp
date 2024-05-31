#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, NULL, NULL};

        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, NULL, NULL};

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteFromBeginning() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
        }
    }

    void deleteFromEnd() {
        if (head != NULL) {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            if (temp->prev != NULL) {
                temp->prev->next = NULL;
            } else {
                head = NULL;
            }

            delete temp;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL."<<endl;
    }
};

int main() {
    DoublyLinkedList myList;

    myList.insertAtEnd(22);
    myList.insertAtEnd(43);
    myList.insertAtEnd(55);
    myList.insertAtEnd(3);
    myList.insertAtEnd(2);
    myList.insertAtEnd(6);
    myList.insertAtEnd(7);
    myList.insertAtEnd(8);

    system("cls");
    cout<<"\nOriginal list: \n\n";
    myList.display();
    system("pause");

    system("cls");
    myList.insertAtBeginning(11);
    cout<<"\nAfter inserting at the beginning: \n\n";
    myList.display();
    system("pause");

    system("cls");
    myList.deleteFromEnd();
    cout<<"\nAfter deleting from the end: \n\n";
    myList.display();
    system("pause");

    system("cls");
    myList.deleteFromBeginning();
    cout<<"\nAfter deleting from the beginning: \n\n";
    myList.display();
    system("pause");

    return 0;
}