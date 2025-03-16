
#include <iostream>

using namespace std;

const int size = 100001;

int main() {
    int n, t;
    int l, r;
    int mem[size] = {0, };
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        mem[l] += 1;
        mem[r] -= 1;
    }
    int ans = mem[0];
    for (int i = 1; i < t + 1; i++) {
        mem[i] += mem[i - 1];
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }
    cout << ans << endl;
    return 0;
}
