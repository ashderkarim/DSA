#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout<<"Pushed: "<<value<<endl;
    }

    void pop() {
        if (top == NULL) {
            cout<<"Stack underflow! Cannot pop element."<<endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        cout<<"Popped: "<<temp->data<<endl;
        delete temp;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    int getTop() {
        if (top == NULL) {
            cout<<"Stack is empty."<<endl;
            return -1; 
        }

        return top->data;
    }

    void display() {
        if (top == NULL) {
            cout<<"Stack is empty."<<endl;
            return;
        }

        cout<<"Stack elements: ";
        Node* current = top;
        while (current != NULL) {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
};

int main() {
    Stack stack;
    int option, value;

    do {
        cout<<"\nPress 1. to push value into the stack."<<endl;
        cout<<"Press 2. to pop value from the stack."<<endl;
        cout<<"Press 3. to display the top element of the stack."<<endl;
        cout<<"Press 4. to check if the stack is empty."<<endl;
        cout<<"Press 5. to display entire stack."<<endl;
        cout<<"Press 6. to exit."<<endl;
        cout<<"\nChoose option (1-6): ";
        cin>>option;

        switch (option) {
            case 1:
                cout<<"Enter value to push: ";
                cin>>value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout<<"Top element: "<<stack.getTop()<<endl;
                break;
            case 4:
                cout<<"Is stack empty? "<<(stack.isEmpty() ? "Yes" : "No")<<endl;
                break;
            case 5:
                stack.display();
                break;
            case 6:
                return 0;
            default:
                cout<<"\nInvalid entry. Please enter between 1-6."<<endl;
                break;
        }

    } while (true);

    return 0;
}
