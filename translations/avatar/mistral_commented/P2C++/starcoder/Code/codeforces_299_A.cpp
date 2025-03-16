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
    sort(a.begin(), a.end());
    cout << a[0] << " ";
    if (any_of(a.begin(), a.end(), [=](int x) { return x % a[0]; })) {
        cout << -1;
    }
    cout << "\n";
    return 0;
}
