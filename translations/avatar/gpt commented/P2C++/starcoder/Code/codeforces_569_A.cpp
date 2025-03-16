#include <iostream>
using namespace std;

int main() {
    int t, s, q, ans;
    cin >> t >> s >> q;
    ans = 0;
    while (s < t) {
        s *= q;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
