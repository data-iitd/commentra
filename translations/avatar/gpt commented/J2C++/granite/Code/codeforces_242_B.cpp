
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int left = *min_element(a.begin(), a.end());
    int right = *max_element(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (a[i] == left && b[i] == right) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
