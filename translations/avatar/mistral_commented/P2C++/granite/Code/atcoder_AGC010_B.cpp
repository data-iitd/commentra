
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
        return 0;
    }

    int k = sum / (n * (n + 1) / 2);
    a.push_back(a[0]);

    if (accumulate(a.begin() + 1, a.end(), 0, [](int sum, int x) { return sum + (k - x + a[0]) % n; })!= 0 ||
        accumulate(a.begin() + 1, a.end(), 0, [](int sum, int x) { return sum + (k - x + a[0]) / n >= 0; })!= n) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}
