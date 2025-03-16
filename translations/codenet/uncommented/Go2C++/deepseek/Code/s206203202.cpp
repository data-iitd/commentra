#include <iostream>
#include <cmath>
using namespace std;

int Abs(int x) {
    return (x < 0) ? -x : x;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int N, K;
    cin >> N >> K;
    int x = N % K;
    x = min(Abs(x - K), x);
    cout << x << endl;
    return 0;
}

