
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int max = 0;
    while (n--) {
        int f, t;
        cin >> f >> t;
        if (max < f + t) {
            max = f + t;
        }
    }
    cout << max(max, s) << endl;
    return 0;
}
// END-OF-CODE