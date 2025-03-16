
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }
    if (ans == n && x > 0) {
        ans--;
    }
    cout << ans << endl;

    return 0;
}

Translate the above C++ code to Rust and end with comment "