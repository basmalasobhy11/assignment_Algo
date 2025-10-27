#include <iostream>
using namespace std;


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

int  fibonacci(int n) {
    if (n == 0)
        return 0;
    int F[2][2] = { {1, 1}, {1, 0} };
    power(F, n - 1);  
    return F[0][0];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
