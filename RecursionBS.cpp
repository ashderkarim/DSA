#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, right, target);
    } else {
        return binarySearch(arr, left, mid - 1, target);
    }
}

int main() {
    int n;
    cout<<"Enter the number of elements in the sorted array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the sorted elements in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout<<"Enter the number you want to find: ";
    cin>>target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != 0) {
        cout<<"Element "<<target<<" found at index "<<result<<endl;
    } else {
        cout<<"Element "<<target<<" not found in the array."<<endl;
    }

    return 0;
}
