
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

int n, m;
int a[100005];
map<int, int> mp;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll ans = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum - a[i] % m + m) % m;
        ans += mp[(sum + a[i]) % m];
        mp[sum] += 1;
    }
    printf("%lld\n", ans);
    return 0;
}
//END-OF-CODE