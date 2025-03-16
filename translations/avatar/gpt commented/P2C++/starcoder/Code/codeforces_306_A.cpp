#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int q = n / m;
    int r = n % m;
    vector<int> a(m, q);
    for (int i = 0; i < r; i++) {
        a[i]++;
    }
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

