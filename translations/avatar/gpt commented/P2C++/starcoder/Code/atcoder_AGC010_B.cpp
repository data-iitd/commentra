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
    int k = accumulate(a.begin(), a.end(), 0) / (n * (n + 1) / 2);
    a.push_back(a[0]);
    if (accumulate(a.begin(), a.end(), 0) % (n * (n + 1) / 2) ||
        any_of(a.begin(), a.end(), [k](int i) { return (k - i + a[i]) / n < 0; })) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
