
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

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 100000 + 10;
const int MAX_LOG_V = 25;
const ll MOD = 1000000007;

int N, A[MAXN];
ll K;

int main() {
    cin >> N >> K;
    REP(i,N) cin >> A[i];
    REP(i,N) A[i]--;

    vector<int> used(N, 0);
    vector<int> idx(N, 0);
    vector<int> pos(N, 0);

    int next = 0, cur = 0;
    while (used[next] == 0) {
        used[next] = 1;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }

    ll a = cur - idx[next];
    ll b = idx[next];
    ll ans = (10000 * a + K - b) % a + b;
    if (b > K) ans = K;
    cout << pos[ans] + 1 << endl;

    return 0;
}
// END-OF-CODE