#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) a += cin.ignore() >> 1;
    for (int i = 0; i < n - 1; i++) b += cin.ignore() >> 1;
    for (int i = 0; i < n - 2; i++) c += cin.ignore() >> 1;
    int x = a - b;
    int y = b - c;
    cout << x << endl;
    cout << y << endl;
    return 0;
}

