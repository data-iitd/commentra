#include <iostream>
using namespace std;

int main() {
    int v1, v2, t, d;
    cin >> v1 >> v2;
    cin >> t;
    cin >> d;

    int a = 1;
    int v = v1;
    int distance = 0;

    for (int i = 0; i < t; i++) {
        if (v - v2 > (t - i - 1) * d) {
            a *= -1;
            v = (t - i - 1) * d + v2;
        }
        distance += v;
        v += a * d;
    }

    cout << distance << endl;

    return 0;
}

