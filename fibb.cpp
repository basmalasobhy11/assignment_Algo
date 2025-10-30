#include <iostream>
using namespace std;
// Dynamic Programming (Bottom-Up) 
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
// Matrix Multiplication 
void multiply(int F[2][2], int B[2][2]) {
    long long r = F[0][0] * B[0][0] + F[0][1] * B[1][0];
    long long s = F[0][0] * B[0][1] + F[0][1] * B[1][1];
    long long t = F[1][0] * B[0][0] + F[1][1] * B[1][0];
    long long u = F[1][0] * B[0][1] + F[1][1] * B[1][1];

    F[0][0] = r;
    F[0][1] = s;
    F[1][0] = t;
    F[1][1] = u;
}


void power(int F[2][2], int n) {
    if (n == 0 || n == 1)
        return;

    int B[2][2] = { {1, 1}, {1, 0} };
    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, B);
}

int  matrix_fibonacci(int n) {
    if (n == 0)
        return 0;
    int F[2][2] = { {1, 1}, {1, 0} };
    power(F, n - 1);
    return F[0][0];
}
// Normal Recursion
int recusive_fibonacci(int n) {
    if (n <= 1) return n;
    return normal_fib(n - 1) + normal_fib(n - 2);
}
int main() {
    int n;
	cout << "Enter a positive integer: ";
    cin >> n;
	cout << 'Choose Fibonacci method:\n';
	cout << "1. Normal Recursion\n";
	cout << "2. Dynamic Programming (Bottom-Up)\n";
	cout << "3. Matrix Multiplication\n";
	int choice;
	cin >> choice;
    switch (choice) {
        case 1:
            cout << "Fibonacci of " << n << " is " << recusive_fibonacci(n) << endl;
            break;
        case 2:
            cout << "Fibonacci of " << n << " is " << fibonacci_bottomUp(n) << endl;
            break;
        case 3:
            cout << "Fibonacci of " << n << " is " << matrix_fibonacci(n) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
	return 0;
}