
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        long long s = 0;
        int x = (int) (log(n) / log(2));
        x++;
        s = -1 * pow(2, x) + 2 + (n * (n + 1)) / 2 - pow(2, x);
        cout << s << endl;
    }
    return 0;
}
//END-OF-CODE