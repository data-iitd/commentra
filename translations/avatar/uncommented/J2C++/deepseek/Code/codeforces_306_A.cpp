#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m, 0);

    if (n % m == 0) {
        fill(a.begin(), a.end(), n / m);
    } else {
        int sub = n / m;
        for (int i = 0; i < m; i++) {
            a[i] = sub;
        }
        int test = n - (sub * m);
        int count = 0;
        for (int i = 0; i < test; i++) {
            a[count]++;
            count = (count + 1) % m;
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

