#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* temp = newNode(dest);
    temp->next = adjList[src];
    adjList[src] = temp;
}

void printGraph(Node* adjList[], int V) {
    for (int i = 0; i < V; i++) {
        Node* temp = adjList[i];
        cout<<"\nAdjacency list of vertex "<<i<<" : "<<i<<" -> ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout<<" NULL.\n";
    }
}

void BFS(Node* adjList[], int V) {
    bool visited[V];
    memset(visited, false, sizeof(visited));

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int front = q.front();
                cout<<front<<" -> ";
                q.pop();

                Node* temp = adjList[front];
                while (temp) {
                    if (!visited[temp->data]) {
                        visited[temp->data] = true;
                        q.push(temp->data);
                    }
                    temp = temp->next;
                }
            }
            cout<<" NULL.\n";
        }
    }
}

bool search(Node* adjList[], int V, int val) {
    for (int i = 0; i < V; i++) {
        Node* temp = adjList[i];
        while (temp) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}

int main() {
    int V = 13;
    Node* adjList[V];
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
    }

    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 2, 6);
    addEdge(adjList, 5, 9);
    addEdge(adjList, 5, 10);
    addEdge(adjList, 4, 8);
    addEdge(adjList, 4, 7);
    addEdge(adjList, 7, 11);
    addEdge(adjList, 7, 12);

    printGraph(adjList, V);

    cout<<"\nBreadth-First Search traversal of the graph is: ";
    BFS(adjList, V);

    int valueToSearch = 8;
    if (search(adjList, V, valueToSearch)) {
        cout<<"\nValue "<<valueToSearch<<" found in the graph.\n";
    } else {
        cout<<"\nValue "<<valueToSearch<<" not found in the graph.\n";
    }

    return 0;
}