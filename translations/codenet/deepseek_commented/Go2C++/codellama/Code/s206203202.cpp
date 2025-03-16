
#include <iostream>

using namespace std;

int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int main() {
    int N, K;
    cin >> N >> K;

    int x = N % K;
    x = min(abs(x-K), x);
    cout << x << endl;

    return 0;
}

