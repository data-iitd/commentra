#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    long long m = 0; // Use long long to avoid overflow
    long long q = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int a = 0; a < n - 1; a++) {
        if (x[a] >= x[a + 1]) {
            q = (x[a] - x[a + 1]) / d + 1;
            m += q;
            x[a + 1] += q * d;
        }
    }

    cout << m << endl;
    return 0;
}

// <END-OF-CODE>
