#include <iostream>
using namespace std;

int main() {
    char m;
    int a, b, c[256], i = 0;

    while (true) {
        cin >> a >> m >> b;
        if (m == '?') {
            break;
        }
        if (m == '+') {
            c[i] = a + b;
        }
        if (m == '-') {
            c[i] = a - b;
        }
        if (m == '*') {
            c[i] = a * b;
        }
        if (m == '/') {
            c[i] = a / b;
        }
        i++;
    }

    for (int j = 0; j < i; j++) {
        cout << c[j] << endl;
    }

    return 0;
}

// <END-OF-CODE>
