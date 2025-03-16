
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

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }
    int ans = 0;
    int parity = 0;
    for (int i = 0; i < n; i++) {
        if ((parity + pos[a[i]]) % 2 == 1) {
            ans++;
        }
        parity = (parity + 1) % 2;
    }
    cout << ans / 2 << endl;
    return 0;
}
