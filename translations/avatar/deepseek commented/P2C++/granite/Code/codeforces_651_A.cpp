
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int ans = max(x + y - 3 + ((y - x) % 3 > 0), 0);
    cout << ans << endl;
    return 0;
}

// END-OF-CODE