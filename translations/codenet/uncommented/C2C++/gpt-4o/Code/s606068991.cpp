#include <iostream>
using namespace std;

void white(int n, int A[]) {
    for (int i = 0; i < n - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[n - 1] << endl;
}

void insertionsort(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] < A[j]) {
                swap(A[i], A[j]);
            }
        }
        white(n, A);
    }
}

int main() {
    int n, A[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    insertionsort(n, A);

    return 0;
}

// <END-OF-CODE>
