
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int h, n;
    cin >> h >> n;
    int a = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a += x;
    }
    if (h > a) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}

