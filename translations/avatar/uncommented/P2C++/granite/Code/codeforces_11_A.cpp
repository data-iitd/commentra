
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
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int m = 0;
    for (int i = 0; i < n - 1; i++) {
        if (x[i] >= x[i + 1]) {
            int q = (x[i] - x[i + 1]) / d + 1;
            m += q;
            x[i + 1] += q * d;
        }
    }
    cout << m << endl;
    return 0;
}
