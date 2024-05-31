#include<iostream>

using namespace std;

class queue
{
    private :
    int* arr;
    int front;
    int rear;
    int capacity;
    public :
    queue(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->front = 0;
        this->rear = 0;

    }
};

int main()
{
    queue* q = new queue(5);
    return 0;

    return 0;
}