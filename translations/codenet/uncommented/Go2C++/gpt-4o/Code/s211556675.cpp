#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to find the maximum of three integers
int max(int a, int b, int c) {
    return std::max(a, std::max(b, c));
}

int main() {
    int A = readInt();
    int B = readInt();
    int C = readInt();
    int K = readInt();

    int ma = max(A, B, C);
    int rest = 0;

    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }

    cout << ma + rest << endl;

    return 0;
}

// <END-OF-CODE>
