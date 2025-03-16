
#include <iostream>
#include <string>

using namespace std;

int main() {
    string k, n, w;
    cin >> k >> n >> w;

    if (1 <= stoi(k) and stoi(w) <= 1000) {
        int total = 0;
        for (int i = 1; i <= stoi(w); i++) {
            total += i * stoi(k);
        }

        if (total > stoi(n)) {
            cout << total - stoi(n);
        } else {
            cout << 0;
        }
    }

    return 0;
}

