#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 1;

    while (true) {
        if (log2(n) == int(log2(n))) {
            break;
        }

        x += 1;
        n -= pow(2, int(log2(n)));
    }

    cout << x << endl;

    return 0;
}

