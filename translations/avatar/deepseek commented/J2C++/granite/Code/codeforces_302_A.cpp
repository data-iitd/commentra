

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int o = 0, e = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            o++;
        } else {
            e++;
        }
    }

    stringstream res;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;

        if ((r - l + 1) % 2 == 1) {
            res << "0\n";
        } else {
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e) {
                res << "1\n";
            } else {
                res << "0\n";
            }
        }
    }

    cout << res.str();

    return 0;
}
