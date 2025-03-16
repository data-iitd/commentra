
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m, n / m);
    int rem = n % m;
    for (int i = 0; i < rem; i++) {
        a[i]++;
    }

    reverse(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

