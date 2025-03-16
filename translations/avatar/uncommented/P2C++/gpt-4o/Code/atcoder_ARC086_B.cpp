#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD 1000000007

int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    for (int i = 0; i < N; ++i) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    if (max_sign == 0) {
        cout << 0 << endl;
    } else {
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; ++i) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        if (max_sign == 1) {
            for (int i = 0; i < N - 1; ++i) {
                cout << i + 1 << " " << i + 2 << endl;
            }
        } else {
            for (int i = N - 1; i > 0; --i) {
                cout << i + 1 << " " << i << endl;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
