#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool found = false;

    for (int k = 0; k < n; k++) {
        int t = a[k];

        for (int i = 0; i < n; i++) {
            if (i != k) {
                for (int j = 0; j < n - 1; j++) {
                    if (i != j && t == (a[i] + a[j])) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
        }
        if (found) {
            cout << k + 1 << " " << i + 1 << " " << j + 1 << endl;
            found = false;
        }
    }

    if (!found) {
        cout << "-1" << endl;
    }

    return 0;
}
