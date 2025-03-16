#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n < 1) {
        if (m < 1) {
            cout << n << " " << m << endl;
            return 0;
        }
        cout << "Impossible" << endl;
        return 0;
    }

    int min, max;
    if (m > n) {
        min = m;
        max = n + m - 1;
        cout << min << " " << max << endl;
    } else {
        min = n;
        max = n + m - 1;
        if (m == 0) {
            max = n;
        }
        cout << min << " " << max << endl;
    }

    return 0;
}

// <END-OF-CODE>
