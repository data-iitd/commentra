
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s, t;

    cin >> n;
    cin >> s;
    cin >> t;

    if (s == t) {
        cout << n << endl;
    } else {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (s[i + j] != t[j]) {
                    break;
                }
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }
        cout << 2 * n - cnt << endl;
    }

    return 0;
}

