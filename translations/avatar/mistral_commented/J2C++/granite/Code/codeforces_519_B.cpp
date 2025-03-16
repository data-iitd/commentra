
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

    int x = 0, y = 0;
    for (int i = 0; i < n - 1; i++) {
        x += a[i];
    }

    for (int i = 0; i < n - 2; i++) {
        y += a[i];
    }

    x = x - a[n - 1];
    y = y - a[n - 2];

    cout << x << endl;
    cout << y << endl;

    return 0;
}

