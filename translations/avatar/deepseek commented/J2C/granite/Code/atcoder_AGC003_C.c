

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

const int MAXN = 1e5 + 2;
const int MOD = 1e9 + 7;
const int oo = 1e9;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        mp[x] = i;
    }
    int bin = 0, diff = 0;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        int idx = mp[x];
        if ((bin % 2)!= (idx % 2)) {
            diff++;
        }
        bin++;
        bin %= 2;
    }
    cout << diff / 2 << endl;
    return 0;
}

