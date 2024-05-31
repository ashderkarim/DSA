#include <iostream>
using namespace std;
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int fibonacciSum(int n) {
    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += fibonacci(i);
    }
    return sum;
}
int main() {
    int n;
    cout<<"Enter the number of terms in the Fibonacci series: ";
    cin>>n;
    int sum = fibonacciSum(n);
    cout<<"Sum of Fibonacci series with "<<n<<" terms is: "<<sum<<endl;

    return 0;
}
