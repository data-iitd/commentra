#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    if (n % m == 0) {
        fill(a.begin(), a.end(), n / m);
    } else {
        int sub = n / m;
        fill(a.begin(), a.end(), sub);

        int test = n - (sub * m);
        int count = 0;
        for (int i = 0; i < test; i++) {
            a[count]++;
            count++;
            if (count >= m) count = 0;
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    return 0;
}

