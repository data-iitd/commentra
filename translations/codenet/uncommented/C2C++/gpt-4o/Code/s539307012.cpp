#include <iostream>
using namespace std;

int main() {
    int n, x, min, m;
    cin >> n >> x >> min;
    x -= min;
    for (int i = 1; i < n; i++) {
        cin >> m;
        x -= m;
        if (min > m) {
            min = m;
        }
    }
    cout << n + x / min << endl;
    return 0;
}

// <END-OF-CODE>
