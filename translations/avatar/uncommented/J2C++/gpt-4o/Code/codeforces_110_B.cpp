#include <iostream>
using namespace std;

int main() {
    int n, p = 97;
    cin >> n;
    char c[n];

    for (int i = 0; i < 4; i++) {
        for (int j = i; j < n; j += 4) {
            c[j] = (char)p;
            p++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << c[i];
    }

    return 0;
}

// <END-OF-CODE>
