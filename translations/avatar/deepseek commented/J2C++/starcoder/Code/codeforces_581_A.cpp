
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, count = 0;
    cin >> a >> b;
    while (true) {
        if (a > 0 && b > 0) {
            count++;
            a--;
            b--;
        } else break;
    }
    int ans = a / 2 + b / 2;
    cout << count << " " << ans << endl;
    return 0;
}

