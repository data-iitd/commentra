#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cassert>
#include <sstream>
#include <iterator>
#include <bitset>
using namespace std;

int main() {
    int x = 0, y = 0, t = 0, n;
    string str;
    cin >> n;
    cin >> str;
    char l[str.length()];
    l = str.c_str();
    for (int i = 0; i < n; i++) {
        if (l[i]!= '4' && l[i]!= '7') {
            t = 1;
        }
    }
    if (t == 1) {
        cout << "NO" << endl;
    } else {
        for (int i = 0; i < n / 2; i++) {
            x = x + (l[i] - '0');
        }
        for (int i = n - 1; i > (n / 2) - 1; i--) {
            y = y + (l[i] - '0');
        }
        if (x == y) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

