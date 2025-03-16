#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int m = 0;
    for (int a = 0; a < n - 1; ++a) {
        if (x[a] >= x[a + 1]) {
            int q = (x[a] - x[a + 1]) / d + 1;
            m += q;
            x[a + 1] += q * d;
        }
    }

    cout << m << endl;

    return 0;
}

