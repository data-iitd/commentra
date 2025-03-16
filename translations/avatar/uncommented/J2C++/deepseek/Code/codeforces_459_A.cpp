#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <limits>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <complex>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
        int dif = abs(y1 - y2);
        cout << (x1 + dif) << " " << y1 << " " << (x1 + dif) << " " << y2 << endl;
    } else if (y1 == y2) {
        int dif = abs(x1 - x2);
        cout << (x1) << " " << (y1 + dif) << " " << (x2) << " " << (y2 + dif) << endl;
    } else if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

