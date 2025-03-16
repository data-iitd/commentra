
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor of two integers using Euclid's algorithm
int gcd(int a, int b) {
    int tmp;

    // If b is greater than a, swap a and b
    if (b > a) {
        tmp = a;
        a = b;
        b = tmp;
    }

    // If b is zero, return a as the gcd
    if (b == 0) {
        return a;
    }

    // Calculate the remainder of the division of a by b, and repeat the process
    int r = -1;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r!= 0);

    // Return the final result
    return a;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> L(N);
    L[0] = A[0];
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]);
    }

    vector<int> R(N);
    R[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i]);
    }

    int answer = max(L[N - 2], R[1]);
    for (int i = 1; i < N - 1; i++) {
        answer = max(answer, gcd(L[i - 1], R[i + 1]));
    }

    cout << answer << endl;

    return 0;
}

