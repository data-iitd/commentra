
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N = 368;
    int m[N] = {0};
    int f[N] = {0};
    int i, a, b;
    char x;
    for (i = 0; i < int(cin); i++) {
        cin >> x >> a >> b;
        a = int(a);
        b = int(b) + 1;
        if (x == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }
    int a = 0, b = 0, c = 0;
    for (i = 0; i < N; i++) {
        a += m[i];
        b += f[i];
        if (min(a, b) > c) {
            c = min(a, b);
        }
    }
    cout << c << endl;
    return 0;
}
