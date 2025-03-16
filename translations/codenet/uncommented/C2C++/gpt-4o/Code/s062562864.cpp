#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, i, j;

    cin >> a >> b >> c >> d;

    i = a * b;
    j = c * d;
    if (i > j) {
        cout << i << endl;
    } else {
        cout << j << endl;
    }

    return 0;
}

// <END-OF-CODE>
