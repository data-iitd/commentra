

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 0) {
        if (m!= 0) {
            cout << "Impossible" << endl;
        } else {
            cout << "0 0" << endl;
        }
        return 0;
    }

    if (m <= n) {
        if (m == 0) {
            m = 1;
        }
        cout << n << " " << m + n - 1 << endl;
        return 0;
    }

    cout << m << " " << m + n - 1 << endl;

    return 0;
}
