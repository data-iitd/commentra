#include <iostream>
using namespace std;

int main() {
    int i = 0, x[10000];

    for (i = 0; i < 10000; i++) {
        x[i] = 0;
    }
    i = 0;
    cin >> x[i];

    while (x[i] != 0) {
        i++;
        cin >> x[i];
    }

    for (int j = 0; j < i; j++) {
        cout << "Case " << j + 1 << ": " << x[j] << endl;
    }

    return 0;
}

// <END-OF-CODE>
