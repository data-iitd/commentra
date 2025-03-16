#include <iostream>
#include <string>
using namespace std;

int main() {
    int x = 0, y = 0;
    int t = 0;
    int n = 0;
    string str;
    char l[100];

    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++) {
        l[i] = str[i];
    }

    for (int i = 0; i < n; i++) {
        if (l[i] != '4' && l[i] != '7') {
            t = 1;
        }
    }

    if (t == 1) {
        cout << "NO" << endl;
    } else {
        int sumX = 0;
        int sumY = 0;

        for (int i = 0; i < n / 2; i++) {
            sumX += l[i] - '0';
        }

        for (int i = n - 1; i > (n / 2) - 1; i--) {
            sumY += l[i] - '0';
        }

        if (sumX == sumY) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

