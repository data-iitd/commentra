
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
    int n;
    cin >> n;
    map<int, int> mp;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
        mp[x] = i;
    }
    int bin = 0, diff = 0;
    while (!q.empty()) {
        int num = q.top();
        q.pop();
        int idx = mp[num];
        if ((bin % 2)!= (idx % 2)) {
            diff++;
        }
        bin++;
        bin %= 2;
    }
    int ans = diff / 2;
    cout << ans << endl;
    return 0;
}
