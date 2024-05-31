#include<iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

Node* InsertAtStart(Node* head, string newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    newNode->prev = NULL;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    
    return newNode;
}

Node* InsertAtMiddle(Node* head, string newData, int position) {
    Node* newNode = new Node();
    newNode->data = newData;
    
    if (position == 1 || head == NULL) {
        newNode->next = head;
        newNode->prev = NULL;
        
        if (head != NULL) {
            head->prev = newNode;
        }
        
        return newNode;
    }
    
    Node* current = head;
    int count = 1;
    
    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;
    
    return head;
}

Node* InsertAtEnd(Node* head, string newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    
    Node* current = head;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
    
    return head;
}

void DisplayDoublyLinkedList(Node* head) {
    Node* current = head;
    
    while (current != NULL) {
        cout<<current->data<<" <-> ";
        current = current->next;
    }
    
    cout<<"NULL"<<endl;
}

int main() {
    Node* head = NULL;
    char repeat;
    string data;
    int option, position;
    
    do {
        system("cls");
        cout<<"\nPress 1. to enter data in the beginning."<<endl;
        cout<<"Press 2. to enter data somewhere in the middle."<<endl;
        cout<<"Press 3. to enter data in the end."<<endl;
        cout<<"Press 4. to display linked list."<<endl;
        cout<<"Press 5. to exit."<<endl;
        cout<<"\nChoose option (1-5): ";
        cin>>option;
        
        switch(option) {
            case 1:
                system("cls");
                cout<<"\nEnter data to insert in the beginning: ";
                cin>>data;
                head = InsertAtStart(head, data);
                break;
            case 2:
                system("cls");
                cout<<"\nEnter data to insert somewhere in the middle: ";
                cin>>data;
                cout<<"\nEnter position to insert at: ";
                cin>>position;
                head = InsertAtMiddle(head, data, position);
                break;
            case 3:
                system("cls");
                cout<<"\nEnter data to insert in the end: ";
                cin>>data;
                head = InsertAtEnd(head, data);
                break;
            case 4:
                system("cls");
                cout<<"\nDoubly Linked List: ";
                DisplayDoublyLinkedList(head);
                break;
            case 5:
                system("cls");
                return 0;
            default:
                system("cls");
                cout<<"\nInvalid entry. Please enter between 1-5."<<endl;
                break;
        }
        
        system("pause");
        system("cls");
        cout<<"\nDo you want to continue(Y/N): ";
        cin>>repeat;
    } while(repeat != 'n' && repeat != 'N');
    
    return 0;
}
