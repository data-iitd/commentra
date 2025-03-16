

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;

    char d = (s < f)? 'R' : 'L';
    string res = "";
    int i = 1, j = s, t, l, r;
    cin >> t >> l >> r;
    int k = 1;

    while (j!= f) {
        if (i > t && k < m) {
            cin >> t >> l >> r;
            k++;
        }

        if (i == t && (l <= j && j <= r || l <= j + (d == 'R'? 1 : -1) && j + (d == 'R'? 1 : -1) <= r)) {
            res += 'X';
        } else {
            res += d;
            j += (d == 'R'? 1 : -1);
        }

        i++;
    }

    cout << res << endl;

    return 0;
}

