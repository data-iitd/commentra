
#include <iostream>
using namespace std;

int main() {
    int n, s, f, t, c = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> f >> t;
        int x = t - (s - f);
        if (x > c) {
            c = x;
        }
    }
    cout << s + c << endl;
    return 0;
}
// END-OF-CODE