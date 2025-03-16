
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <bitset>
using namespace std;

int main() {
    int t, s, q;
    cin >> t >> s >> q;
    int ans = 0;
    while (s < t) {
        s *= q;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}

