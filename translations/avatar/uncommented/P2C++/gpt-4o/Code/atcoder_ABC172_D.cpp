#include <iostream>
using namespace std;

long long rs() {
    string s;
    getline(cin, s);
    return s;
}

int ri() {
    int x;
    cin >> x;
    return x;
}

int main() {
    int N = ri();
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += i * (N / i) * (N / i + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
