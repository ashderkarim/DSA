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

struct QueueArray {
    int arr[MAX_SIZE];
    int front, rear;

    QueueArray() {
        front = rear = -1;
    }
};

struct QueueLinkedList {
    Node* front;
    Node* rear;

    QueueLinkedList() {
        front = rear = NULL;
    }
};

void enqueue(QueueArray& queue, int value) {
    if (queue.rear == MAX_SIZE - 1) {
        cout<<"Queue overflow! Cannot enqueue element."<<endl;
        return;
    }

    if (queue.front == -1) {
        queue.front = 0;
    }

    queue.arr[++queue.rear] = value;
    cout<<"Enqueued: "<<value<<endl;
}

void dequeue(QueueArray& queue) {
    if (queue.front == -1) {
        cout<<"Queue underflow! Cannot dequeue element."<<endl;
        return;
    }

    cout<<"Dequeued: "<<queue.arr[queue.front++]<<endl;

    if (queue.front > queue.rear) {
        queue.front = queue.rear = -1;
    }
}

bool isEmpty(QueueArray& queue) {
    return (queue.front == -1);
}

bool isFull(QueueArray& queue) {
    return (queue.rear == MAX_SIZE - 1);
}

int getFront(QueueArray& queue) {
    if (queue.front == -1) {
        cout<<"Queue is empty."<<endl;
        return -1; 
    }

    return queue.arr[queue.front];
}

void display(QueueArray& queue) {
    if (queue.front == -1) {
        cout<<"Queue is empty."<<endl;
        return;
    }

    cout<<"Queue elements: ";
    for (int i = queue.front; i <= queue.rear; ++i) {
        cout<<queue.arr[i]<<" ";
    }
    cout<<endl;
}

void enqueue(QueueLinkedList& queue, int value) {
    Node* newNode = new Node(value);
    if (queue.rear == NULL) {
        queue.front = queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }

    cout<<"Enqueued: "<<value<<endl;
}

void dequeue(QueueLinkedList& queue) {
    if (queue.front == NULL) {
        cout<<"Queue underflow! Cannot dequeue element."<<endl;
        return;
    }

    Node* temp = queue.front;
    queue.front = queue.front->next;

    if (queue.front == NULL) {
        queue.rear = NULL;
    }

    cout<<"Dequeued: "<<temp->data<<endl;
    delete temp;
}

bool isEmpty(QueueLinkedList& queue) {
    return (queue.front == NULL);
}

int getFront(QueueLinkedList& queue) {
    if (queue.front == NULL) {
        cout<<"Queue is empty."<<endl;
        return -1; 
    }

    return queue.front->data;
}

void display(QueueLinkedList& queue) {
    if (queue.front == NULL) {
        cout<<"Queue is empty."<<endl;
        return;
    }

    cout<<"Queue elements: ";
    Node* current = queue.front;
    while (current != NULL) {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main() {
    int option;
    QueueArray queueArray;
    QueueLinkedList queueLinkedList;
    int value;

    do {
        cout<<"\nPress 1. to use an array-based queue."<<endl;
        cout<<"Press 2. to use a linked list-based queue."<<endl;
        cout<<"Press 3. to exit."<<endl;
        cout<<"\nChoose option (1-3): ";
        cin>>option;

        switch (option) {
            case 1: {
                int arrayOption;

                do {
                    cout<<"\nPress 1. to enqueue value into the queue."<<endl;
                    cout<<"Press 2. to dequeue value from the queue."<<endl;
                    cout<<"Press 3. to display the front element of the queue."<<endl;
                    cout<<"Press 4. to check if the queue is empty."<<endl;
                    cout<<"Press 5. to check if the queue is full."<<endl;
                    cout<<"Press 6. to display entire queue."<<endl;
                    cout<<"Press 7. to exit."<<endl;
                    cout<<"\nChoose option (1-7): ";
                    cin>>arrayOption;

                    switch (arrayOption) {
                        case 1:
                            cout<<"Enter value to enqueue: ";
                            cin>>value;
                            enqueue(queueArray, value);
                            break;
                        case 2:
                            dequeue(queueArray);
                            break;
                        case 3:
                            cout<<"Front element: "<<getFront(queueArray)<<endl;
                            break;
                        case 4:
                            cout<<"Is queue empty? "<<(isEmpty(queueArray) ? "Yes" : "No")<<endl;
                            break;
                        case 5:
                            cout<<"Is queue full? "<<(isFull(queueArray) ? "Yes" : "No")<<endl;
                            break;
                        case 6:
                            display(queueArray);
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
                    cout<<"\nPress 1. to enqueue value into the queue."<<endl;
                    cout<<"Press 2. to dequeue value from the queue."<<endl;
                    cout<<"Press 3. to display the front element of the queue."<<endl;
                    cout<<"Press 4. to check if the queue is empty."<<endl;
                    cout<<"Press 5. to display entire queue."<<endl;
                    cout<<"Press 6. to exit."<<endl;
                    cout<<"\nChoose option (1-6): ";
                    cin>>linkedListOption;

                    switch (linkedListOption) {
                        case 1:
                            cout<<"Enter value to enqueue: ";
                            cin>>value;
                            enqueue(queueLinkedList, value);
                            break;
                        case 2:
                            dequeue(queueLinkedList);
                            break;
                        case 3:
                            cout<<"Front element: "<<getFront(queueLinkedList)<<endl;
                            break;
                        case 4:
                            cout<<"Is queue empty? "<<(isEmpty(queueLinkedList) ? "Yes" : "No")<<endl;
                            break;
                        case 5:
                            display(queueLinkedList);
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
