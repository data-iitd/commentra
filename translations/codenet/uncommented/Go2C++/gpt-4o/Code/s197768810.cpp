#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    int sum = 0;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum > n) {
        cout << "-1" << endl;
        return 0;
    }

    cout << n - sum << endl;
    return 0;
}

// <END-OF-CODE>
