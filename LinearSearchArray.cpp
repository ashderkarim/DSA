#include <iostream>
using namespace std;
int linearSearch(int arr[], int target, int index, int n) {
    if (index == n) {
        return 0;
    }
    if (arr[index] == target) {
        return index;
    }   
    return linearSearch(arr, target, index + 1, n);
}
int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout<<"Enter element "<<i + 1<<": ";
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the number you want to find: ";
    cin>>target;
    int result = linearSearch(arr, target, 0, n);
    if(result != 0) {
        cout<<"Element "<<target<<" found at index "<<result<<endl;
    }
	else {
        cout<<"Element "<<target<<" not found in the array."<<endl;
    }
    return 0;
}