#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        int a = 0, b = 0;
        for (char j : s) {
            if (j == x[0]) {
                a++;
            } else if (j == x[1]) {
                b++;
            } else {
                ans += min(a, b);
                a = 0;
                b = 0;
            }
        }
        ans += min(a, b);
    }
    cout << ans << endl;
    return 0;
}

