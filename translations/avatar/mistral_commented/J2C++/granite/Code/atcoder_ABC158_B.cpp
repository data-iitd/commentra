

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N, A, B;
    cin >> N >> A >> B;

    long long k = 0;

    if (isValidInput(N, A, B)) {
        if (A + B <= N) {
            k = calculateK(N, A, B);

            if (remainingPartGreaterThanA(N, k, A)) {
                printResult(N, k, A);
            } else {
                printResult(N, k, A);
            }
        } else if (A + B > N && A <= N) {
            printA();
        } else {
            printN();
        }
    }

    return 0;
}

bool isValidInput(long long n, long long a, long long b) {
    return (1 <= n && n <= pow(10, 18) && 0 <= a && 0 <= b && 0 < a + b && a + b <= pow(10, 18));
}

long long calculateK(long long n, long long a, long long b) {
    return n / (a + b);
}

bool remainingPartGreaterThanA(long long n, long long k, long long a) {
    return (n - k * (a + b)) > a;
}

void printResult(long long n, long long k, long long a) {
    long long result = 0;
    if (remainingPartGreaterThanA(n, k, a)) {
        result = a * k + (n - k * (a + b)) - (n - (k * (a + b) + a));
    } else {
        result = a * k + (n - k * (a + b));
    }
    cout << result << endl;
}

void printA() {
    cout << A << endl;
}

void printN() {
    cout << N << endl;
}

