
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (s[i + j]!= t[j]) {
                break;
            }
            if (j == n - i - 1) {
                cnt = n - i;
            }
        }
    }

    if (cnt == 0) {
        cout << 2 * n << endl;
    } else {
        cout << 2 * n - cnt << endl;
    }

    return 0;
}

