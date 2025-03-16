#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int c = 0;

    for (int i = 0; i < 2; i++) {
        c += max(a, b);
        if (a >= b) {
            a--;
        } else {
            b--;
        }
    }

    cout << c << endl;

    return 0;
}

