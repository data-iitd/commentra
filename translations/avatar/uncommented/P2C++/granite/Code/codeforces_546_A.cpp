
#include <iostream>
#include <string>
using namespace std;

int main() {
    string k, n, w;
    getline(cin, k);
    getline(cin, n);
    getline(cin, w);
    if (1 <= stoi(k) && stoi(w) <= 1000) {
        int total = 0;
        for (int i = 1; i <= stoi(w); i++) {
            total += i * stoi(k);
        }
        if (total > stoi(n)) {
            cout << total - stoi(n) << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
