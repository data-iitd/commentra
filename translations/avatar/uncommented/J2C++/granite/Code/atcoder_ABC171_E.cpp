
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <assert.h>
#include <array>
#include <tuple>
#include < initializer_list>
#include <forward_list>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        r ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i!= 0) {
            cout << " ";
        }
        cout << (r ^ a[i]);
    }
    cout << endl;
    return 0;
}

