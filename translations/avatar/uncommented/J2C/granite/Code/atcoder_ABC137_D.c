
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define clr(a, b) memset((a), (b), sizeof(a))
#defineSz(a) ((int)(a).size())
#define endl '\n'

const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll llinf = 1e18;
const int MAXN = 1e5 + 9;
const int MOD = 1e9 + 7;

struct Job {
    int a, b;
    bool operator < (const Job &rhs) const {
        if (a == rhs.a) return b > rhs.b;
        return a < rhs.a;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    priority_queue<Job> q;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        q.push({a, b});
    }
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> job;
    for (int i = 1; i <= m; i++) {
        while (!q.empty() && q.top().a <= i) {
            job.push(q.top().b);
            q.pop();
        }
        if (!job.empty()) {
            ans += job.top();
            job.pop();
        }
    }
    printf("%d\n", ans);
    return 0;
}
//END-OF-CODE