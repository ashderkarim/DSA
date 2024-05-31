#include<iostream>

using namespace std;

class Node
{
    private :
    int data;
    Node* next;
    public :
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void setNext(Node* next)
    {
        this->next = next;
        
    }
    Node* getNext()
    {
        return this->next;
    }
    int getData()
    {
        return this->data;
    }
};
 int main()
 {
        Node* node = new Node(10);
        cout<<node->getData()<<endl;

        return 0;
 }
