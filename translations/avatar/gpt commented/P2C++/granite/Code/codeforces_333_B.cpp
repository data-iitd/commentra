
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> b(2 * n, 1);
    b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        b[r - 1] = b[n + c - 1] = 0;
    }

    if (n % 2 && b[n / 2] && b[n + n / 2]) {
        b[n / 2] = 0;
    }

    int count = 0;
    for (int i = 0; i < 2 * n; i++) {
        count += b[i];
    }

    cout << count << endl;

    return 0;
}
