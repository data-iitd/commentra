#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int c = 0;

    if (a == 1 && b == 1) {
        cout << 0 << endl;
        return 0;
    }

    while (a >= 1 || b >= 1) {
        if (a >= b) {
            b++;
            a -= 2;
        } else {
            a++;
            b--;
        }

        if (a <= 0 || b <= 0) {
            c++;
            break;
        }

        c++;
    }

    cout << c << endl;

    return 0;
}

