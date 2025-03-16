
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <cctype>
#include <utility>
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
    if (m > n) {
        int min = m;
        int max = n + m - 1;
        cout << min << " " << max << endl;
    }
    if (m <= n) {
        int min = n;
        int max = n + m - 1;
        if (m == 0) {
            max = n;
        }
        cout << min << " " << max << endl;
    }
    return 0;
}
