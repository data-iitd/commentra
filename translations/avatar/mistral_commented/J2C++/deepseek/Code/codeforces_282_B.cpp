#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> ch(n);
    int s1 = 0, s2 = 0;
    int i, j = 0, flag = 0;

    for (i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        int temp1 = s1 + x;
        int temp2 = s2 + y;

        if (abs(temp1 - temp2) <= 500) {
            s1 += x;
            ch[j++] = 'A';
            continue;
        }

        if (abs(temp1 - s2) <= 500) {
            s2 += y;
            ch[j++] = 'G';
            continue;
        }

        flag = 1;
        break;
    }

    if (flag == 1)
        cout << -1 << endl;
    else {
        string ans;
        for (char c : ch) {
            ans += c;
        }
        cout << ans << endl;
    }

    return 0;
}
