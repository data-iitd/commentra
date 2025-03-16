
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 5 && b == 5) {
        if (c == 17) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

