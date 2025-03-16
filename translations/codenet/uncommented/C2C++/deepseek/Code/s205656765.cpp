#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    X /= 50;
    int kosu = 0;

    for (int i = 0; i <= A; ++i) {
        for (int j = 0; j <= B; ++j) {
            for (int k = 0; k <= C; ++k) {
                if (X == (10 * i) + (2 * j) + k) {
                    ++kosu;
                }
            }
        }
    }

    cout << kosu << endl;

    return 0;
}

