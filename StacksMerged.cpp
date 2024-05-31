#include<iostream>
using namespace std;

#define MAX_SIZE 10

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

struct StackArray {
    int arr[MAX_SIZE];
    int top;

    StackArray() {
        top = -1;
    }
};

struct StackLinkedList {
    Node* top;

    StackLinkedList() {
        top = NULL;
    }
};

void push(StackArray& stack, int value) {
    if (stack.top == MAX_SIZE - 1) {
        cout<<"Stack overflow! Cannot push element."<<endl;
        return;
    }

    stack.arr[++stack.top] = value;
    cout<<"Pushed: "<<value<<endl;
}

void pop(StackArray& stack) {
    if (stack.top == -1) {
        cout<<"Stack underflow! Cannot pop element."<<endl;
        return;
    }

    cout<<"Popped: "<<stack.arr[stack.top--]<<endl;
}

bool isEmpty(StackArray& stack) {
    return (stack.top == -1);
}

bool isFull(StackArray& stack) {
    return (stack.top == MAX_SIZE - 1);
}

int getTop(StackArray& stack) {
    if (stack.top == -1) {
        cout<<"Stack is empty."<<endl;
        return -1; 
    }

    return stack.arr[stack.top];
}

void display(StackArray& stack) {
    if (stack.top == -1) {
        cout<<"Stack is empty."<<endl;
        return;
    }

    cout<<"Stack elements: ";
    for (int i = 0; i <= stack.top; ++i) {
        cout<<stack.arr[i]<<" ";
    }
    cout<<endl;
}

void push(StackLinkedList& stack, int value) {
    Node* newNode = new Node(value);
    newNode->next = stack.top;
    stack.top = newNode;
    cout<<"Pushed: "<<value<<endl;
}

void pop(StackLinkedList& stack) {
    if (stack.top == NULL) {
        cout<<"Stack underflow! Cannot pop element."<<endl;
        return;
    }

    Node* temp = stack.top;
    stack.top = stack.top->next;
    cout<<"Popped: "<<temp->data<<endl;
    delete temp;
}

bool isEmpty(StackLinkedList& stack) {
    return (stack.top == NULL);
}

int getTop(StackLinkedList& stack) {
    if (stack.top == NULL) {
        cout<<"Stack is empty."<<endl;
        return -1; 
    }

    return stack.top->data;
}

void display(StackLinkedList& stack) {
    if (stack.top == NULL) {
        cout<<"Stack is empty."<<endl;
        return;
    }

    cout<<"Stack elements: ";
    Node* current = stack.top;
    while (current != NULL) {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main() {
    int option;
    StackArray stackArray;
    StackLinkedList stackLinkedList;
    int value;

    do {
        cout<<"\nPress 1. to use an array-based stack."<<endl;
        cout<<"Press 2. to use a linked list-based stack."<<endl;
        cout<<"Press 3. to exit."<<endl;
        cout<<"\nChoose option (1-3): ";
        cin>>option;

        switch (option) {
            case 1: {
                int arrayOption;

                do {
                    cout<<"\nPress 1. to push value into the stack."<<endl;
                    cout<<"Press 2. to pop value from the stack."<<endl;
                    cout<<"Press 3. to display the top element of the stack."<<endl;
                    cout<<"Press 4. to check if the stack is empty."<<endl;
                    cout<<"Press 5. to check if the stack is full."<<endl;
                    cout<<"Press 6. to display entire stack."<<endl;
                    cout<<"Press 7. to exit."<<endl;
                    cout<<"\nChoose option (1-7): ";
                    cin>>arrayOption;

                    switch (arrayOption) {
                        case 1:
                            cout<<"Enter value to push: ";
                            cin>>value;
                            push(stackArray, value);
                            break;
                        case 2:
                            pop(stackArray);
                            break;
                        case 3:
                            cout<<"Top element: "<<getTop(stackArray)<<endl;
                            break;
                        case 4:
                            cout<<"Is stack empty? "<<(isEmpty(stackArray) ? "Yes" : "No")<<endl;
                            break;
                        case 5:
                            cout<<"Is stack full? "<<(isFull(stackArray) ? "Yes" : "No")<<endl;
                            break;
                        case 6:
                            display(stackArray);
                            break;
                        case 7:
                            break;
                        default:
                            cout<<"\nInvalid entry. Please enter between 1-7."<<endl;
                            break;
                    }

                } while (arrayOption != 7);

                break;
            }
            case 2: {
                int linkedListOption;

                do {
                    cout<<"\nPress 1. to push value into the stack."<<endl;
                    cout<<"Press 2. to pop value from the stack."<<endl;
                    cout<<"Press 3. to display the top element of the stack."<<endl;
                    cout<<"Press 4. to check if the stack is empty."<<endl;
                    cout<<"Press 5. to display entire stack."<<endl;
                    cout<<"Press 6. to exit."<<endl;
                    cout<<"\nChoose option (1-6): ";
                    cin>>linkedListOption;

                    switch (linkedListOption) {
                        case 1:
                            cout<<"Enter value to push: ";
                            cin>>value;
                            push(stackLinkedList, value);
                            break;
                        case 2:
                            pop(stackLinkedList);
                            break;
                        case 3:
                            cout<<"Top element: "<<getTop(stackLinkedList)<<endl;
                            break;
                        case 4:
                            cout<<"Is stack empty? "<<(isEmpty(stackLinkedList) ? "Yes" : "No")<<endl;
                            break;
                        case 5:
                            display(stackLinkedList);
                            break;
                        case 6:
                            break;
                        default:
                            cout<<"\nInvalid entry. Please enter between 1-6."<<endl;
                            break;
                    }

                } while (linkedListOption != 6);

                break;
            }
            case 3:
                return 0;
            default:
                cout<<"\nInvalid entry. Please enter between 1-3."<<endl;
                break;
        }

    } while (true);

    return 0;
}
