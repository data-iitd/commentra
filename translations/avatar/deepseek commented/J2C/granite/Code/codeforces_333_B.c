
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> bannedRows, bannedCols;
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        if (r > 1 && r < n) bannedRows.insert(r);
        if (c > 1 && c < n) bannedCols.insert(c);
    }
    int ans = (n - 2) * 2;
    ans -= bannedRows.size();
    ans -= bannedCols.size();
    if (n % 2!= 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows.count(mid) &&!bannedCols.count(mid)) ans--;
    }
    cout << ans << endl;
    return 0;
}
