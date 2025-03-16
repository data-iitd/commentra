#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, count;
    cin >> n >> count;
    int a = (n + 1) / 2;
    int b = n / 2;
    int max = a * a + b * b;

    if (count > max) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    for (int i = 0; i < n; i++) {
        string row;
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 && count > 0) {
                row += 'L';
                count--;
            } else {
                row += 'S';
            }
        }
        cout << row << endl;
    }

    return 0;
}

