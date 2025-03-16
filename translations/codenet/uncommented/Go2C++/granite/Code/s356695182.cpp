
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int len = 5;
    vector<int> l(len);
    for (int i = 0; i < len; i++) {
        cin >> l[i];
    }
    int n1 = l[0] * l[3] + l[1] * l[4];
    int n2 = 2 * l[2] * max(l[3], l[4]);
    int n3 = 2 * l[2] * min(l[3], l[4]) + (doch(l));
    int res = min(n1, n2, n3);
    cout << res << endl;
    return 0;
}

int doch(vector<int> l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

