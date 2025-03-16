#include <iostream>
using namespace std;

int task4(int A, int B, int n) {
    for (int X = -1000; X <= 1000; X++) {
        if (A * (pow(X, n)) == B) {
            return X;
        }
    }
    return -1; // Indicating no solution found
}

int main() {
    int A, B, n;
    cin >> A >> B >> n;
    int result = task4(A, B, n);
    if (result == -1) {
        cout << "No solution" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}

// <END-OF-CODE>
