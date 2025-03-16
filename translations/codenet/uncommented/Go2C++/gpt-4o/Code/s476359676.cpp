#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int aPrev = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a > i || a > aPrev + 1) {
            cout << -1 << endl;
            return 0;
        } else if (a == aPrev + 1) {
            ans++;
        } else {
            ans += a;
        }
        aPrev = a;
    }
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
