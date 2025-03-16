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
    int f = 0;
    for (int k = 0; k < n; k++) {
        int t = a[k];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (i != j && t == (a[i] + a[j])) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) break;
        }
        if (f == 1) {
            cout << k + 1 << " " << i + 1 << " " << j + 1 << endl;
            break;
        }
    }
    if (f == 0) {
        cout << "-1" << endl;
    }
    return 0;
}
