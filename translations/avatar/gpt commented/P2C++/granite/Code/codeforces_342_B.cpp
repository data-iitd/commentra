
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;

    int d = s < f? 1 : -1;
    char c = s < f? 'R' : 'L';

    string res = "";
    int i = 1, j = s;
    int t, l, r;
    cin >> t >> l >> r;
    int k = 1;

    while (j!= f) {
        if (i > t && k < m) {
            cin >> t >> l >> r;
            k++;
        }

        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res += 'X';
        } else {
            res += c;
            j += d;
        }

        i++;
    }

    cout << res << endl;

    return 0;
}

