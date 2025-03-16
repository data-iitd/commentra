
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string number;
    cin >> number;
    int h1 = 0, h2 = 0;
    for (int i = 0; i < n; i++) {
        if (number[i]!= '4' && number[i]!= '7') {
            cout << "NO";
            return 0;
        }
        if (i < n / 2) {
            h1 += number[i] - '0';
        } else {
            h2 += number[i] - '0';
        }
    }
    if (h1 == h2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

