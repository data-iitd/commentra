
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    int curr = r;
    int s = 0;

    while (curr) {
        s++;
        curr /= 10;
    }

    int first = pow(10, s);
    int second = first / 2;

    int ans = -1;

    for (int i : {l, r, first, second}) {
        if (i >= l && i <= r) {
            curr = i;
            string rev = "";

            for (char k : to_string(curr)) {
                rev += to_string(9 - (k - '0'));
            }

            ans = max(ans, stoi(rev) * curr);
        }
    }

    cout << ans << endl;

    return 0;
}
