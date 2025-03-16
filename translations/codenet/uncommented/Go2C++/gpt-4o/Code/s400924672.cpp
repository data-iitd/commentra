#include <iostream>
using namespace std;

int main() {
    int r, D, x;
    cin >> r >> D >> x;

    for (int i = 1; i <= 10; i++) {
        cout << r * x - D << endl;
        x = r * x - D;
    }

    return 0;
}

// <END-OF-CODE>
