#include <iostream>
using namespace std;
int fibonacci_bottomUp(int n) {
    if (n <= 1) return n;

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}
int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << fibonacci_bottomUp(n) << endl;
    return 0;
}
