
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % (n * (n + 1) / 2)!= 0) {
        cout << "NO" << endl;
    } else {
        int k = sum / (n * (n + 1) / 2);
        a.push_back(a[0]);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if ((k - a[i] + a[i + 1]) % n!= 0 || (k - a[i] + a[i + 1]) / n < 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
