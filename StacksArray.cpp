#include<iostream>
using namespace std;

#define MAX_SIZE 10

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout<<"Stack overflow! Cannot push element."<<endl;
            return;
        }

        arr[++top] = value;
        cout<<"Pushed: "<<value<<endl;
    }

    void pop() {
        if (top == -1) {
            cout<<"Stack underflow! Cannot pop element."<<endl;
            return;
        }

        cout<<"Popped: "<<arr[top--]<<endl;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    int getTop() {
        if (top == -1) {
            cout<<"Stack is empty."<<endl;
            return -1; 
        }

        return arr[top];
    }

    void display() {
        if (top == -1) {
            cout<<"Stack is empty."<<endl;
            return;
        }

        cout<<"Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout<<arr[i]<<" ";
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
        cout<<"Press 5. to check if the stack is full."<<endl;
        cout<<"Press 6. to display entire stack."<<endl;
        cout<<"Press 7. to exit."<<endl;
        cout<<"\nChoose option (1-7): ";
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
                cout<<"Is stack full? "<<(stack.isFull() ? "Yes" : "No")<<endl;
                break;
            case 6:
                stack.display();
                break;
            case 7:
                return 0;
            default:
                cout<<"\nInvalid entry. Please enter between 1-7."<<endl;
                break;
        }

    } while (true);

    return 0;
}
