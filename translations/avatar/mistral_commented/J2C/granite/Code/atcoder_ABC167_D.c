

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
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
#include <functional>
#include <utility>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

#define rep0(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<=n; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define trav(a,x) for(auto& a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()

const int MOD = 1000000007;
const int MAX = INT_MAX;
const ll LMAX = LLONG_MAX;
const int IMAX = INT_MAX;
const ll LMIN = LLONG_MIN;

void doIt() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep0(i,N) {
        cin >> A[i];
        A[i]--;
    }

    vector<int> used(N, 0);
    vector<int> idx(N, 0);
    vector<int> pos(N, 0);
    int next = 0, cur = 0;

    while (!used[next]) {
        used[next] = 1;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }

    int a = cur - idx[next];
    int b = idx[next];
    int ans = (10000 * a + K - b + MOD) % a + b;
    if (b > K) {
        ans = K;
    }

    cout << pos[ans] + 1 << endl;
}

int main() {
    doIt();
    return 0;
}

Translate the above C code to Python and end with comment "