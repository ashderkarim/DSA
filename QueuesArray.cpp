#include<iostream>
using namespace std;

#define MAX_SIZE 10

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == MAX_SIZE - 1) {
            cout<<"Queue overflow! Cannot enqueue element."<<endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        arr[++rear] = value;
        cout<<"Enqueued: "<<value<<endl;
    }

    void dequeue() {
        if (front == -1) {
            cout<<"Queue underflow! Cannot dequeue element."<<endl;
            return;
        }

        cout<<"Dequeued: "<<arr[front++]<<endl;

        if (front > rear) {
            front = rear = -1;
        }
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    int getFront() {
        if (front == -1) {
            cout<<"Queue is empty."<<endl;
            return -1; 
        }

        return arr[front];
    }

    void display() {
        if (front == -1) {
        \
        
        
        cout<<"Queue is empty."<<endl;
            return;
        }


        cout<<"Queue elements: ";
        for (int i = front; i <= rear; ++i) {
            cout<<arr[i]<<" ";
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
        cout<<"Press 5. to check if the queue is full."<<endl;
        cout<<"Press 6. to display entire queue."<<endl;
        cout<<"Press 7. to exit."<<endl;
        cout<<"\nChoose option (1-7): ";
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
                cout<<"Is queue full? "<<(queue.isFull() ? "Yes" : "No")<<endl;
                break;
            case 6:
                queue.display();
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
