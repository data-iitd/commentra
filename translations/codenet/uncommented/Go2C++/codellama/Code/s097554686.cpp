#include <iostream>

using namespace std;

int main() {
    int n, t, l, r;
    int mem[100001] = {0};
    int ans = 0;
    cin >> n;
    cin >> t;
    for (int i = 0; i < n; i++) {
        cin >> l;
        cin >> r;
        mem[l] += 1;
        mem[r] -= 1;
    }
    ans = mem[0];
    for (int i = 1; i < t + 1; i++) {
        mem[i] += mem[i - 1];
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }
    cout << ans << endl;
    return 0;
}

