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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout<<"Enqueued: "<<value<<endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout<<"Queue underflow! Cannot dequeue element."<<endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        cout<<"Dequeued: "<<temp->data<<endl;
        delete temp;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    int getFront() {
        if (front == NULL) {
            cout<<"Queue is empty."<<endl;
            return -1; 
        }

        return front->data;
    }

    void display() {
        if (front == NULL) {
            cout<<"Queue is empty."<<endl;
            return;
        }

        cout<<"Queue elements: ";
        Node* current = front;
        while (current != NULL) {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
};

int main() {
    Queue queue;
    int option, value;

    do {
        cout<<"\nPress 1. to enqueue value into the queue."<<endl;
        cout<<"Press 2. to dequeue value from the queue."<<endl;
        cout<<"Press 3. to display the front element of the queue."<<endl;
        cout<<"Press 4. to check if the queue is empty."<<endl;
        cout<<"Press 5. to display entire queue."<<endl;
        cout<<"Press 6. to exit."<<endl;
        cout<<"\nChoose option (1-6): ";
        cin>>option;

        switch (option) {
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout<<"Front element: "<<queue.getFront()<<endl;
                break;
            case 4:
                cout<<"Is queue empty? "<<(queue.isEmpty() ? "Yes" : "No")<<endl;
                break;
            case 5:
                queue.display();
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
