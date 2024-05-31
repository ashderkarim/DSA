#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& heap, int n, int index, bool isMaxHeap) {
    int largestOrSmallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (isMaxHeap && left < n && heap[left] > heap[largestOrSmallest])
        largestOrSmallest = left;

    if (isMaxHeap && right < n && heap[right] > heap[largestOrSmallest])
        largestOrSmallest = right;

    if (!isMaxHeap && left < n && heap[left] < heap[largestOrSmallest])
        largestOrSmallest = left;

    if (!isMaxHeap && right < n && heap[right] < heap[largestOrSmallest])
        largestOrSmallest = right;

    if (largestOrSmallest != index) {
        swap(heap[index], heap[largestOrSmallest]);
        heapify(heap, n, largestOrSmallest, isMaxHeap);
    }
}

void buildHeap(vector<int>& heap, bool isMaxHeap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i, isMaxHeap);
    }
}

void insertElement(vector<int>& heap, int element, bool isMaxHeap) {
    heap.push_back(element);
    int n = heap.size();
    int index = n - 1;

    while (index > 0) {
        int parent = (index - 1) / 2;
        if ((isMaxHeap && heap[index] > heap[parent]) || (!isMaxHeap && heap[index] < heap[parent])) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

int extractRootElement(vector<int>& heap, bool isMaxHeap) {
    if (heap.empty()) {
        cout<<"Heap is empty. Cannot extract element.\n";
        return -1;
    }

    int root = heap[0];
    int lastElement = heap.back();
    heap[0] = lastElement;
    heap.pop_back();

    heapify(heap, heap.size(), 0, isMaxHeap);

    return root;
}

void displayHeap(const vector<int>& heap) {
    cout<<"Current Heap: ";
    int displayLimit = min(10, static_cast<int>(heap.size()));
    for (int i = 0; i < displayLimit; ++i) {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> heap;
    bool isMaxHeap;

    cout<<"Enter '1' for Max Heap or '0' for Min Heap: ";
    cin>>isMaxHeap;

    while (true) {
        cout<<"\nChoose operation:\n";
        cout<<"1. Insert element\n";
        cout<<"2. Extract root element\n";
        cout<<"3. Display entire heap\n";
        cout<<"4. Quit\n";
        int choice;
        cin>>choice;

        switch (choice) {
            case 1: {
                int element;
                cout<<"Enter element to insert: ";
                cin>>element;
                insertElement(heap, element, isMaxHeap);
                cout<<"Element inserted.\n";
                break;
            }
            case 2: {
                int root = extractRootElement(heap, isMaxHeap);
                if (root != -1)
                    cout<<"Extracted root element: "<<root<<endl;
                break;
            }
            case 3:
                displayHeap(heap);
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

