#include <iostream>
using namespace std;

int linearsearch(int S[], int n, int key) {
    int i = 0;
    while (S[i] != key) {
        i++;
        if (i >= n) {
            return 1; // Key not found
        }
    }
    return 0; // Key found
}

int main() {
    int n, q, S[10000], T[10000];
    int count = 0, key;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    cin >> q;
    for (int j = 0; j < q; j++) {
        cin >> T[j];
    }

    for (int j = 0; j < q; j++) {
        key = T[j];
        if (linearsearch(S, n, key) == 1) { // Check if key is not found
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
