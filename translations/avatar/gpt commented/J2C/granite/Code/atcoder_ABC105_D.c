
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <bitset>
#include <fstream>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i, a, b) for(int i=(a); i<(b); ++i)
#define rep(i, n) forr(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define each(i, c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define present(c, x) ((c).find(x)!= (c).end())
#define cpresent(c, x) (find(all(c), x)!= (c).end())

#define clr(a, b) memset((a), (b),sizeof(a))
#define copy(a, b) memcpy((a), (b), sizeof(a))

#define debug(x) cout << #x << " = " << (x) << endl;
#define print(x) cout << (x) << " ";
#define println(x) cout << (x) << endl;

#define read(x) scanf("%d", &x)
#define read2(x, y) scanf("%d%d", &x, &y)
#define read3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define readll(x) scanf("%lld", &x)
#define readll2(x, y) scanf("%lld%lld", &x, &y)
#define readll3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define readstr(x) scanf("%s", x)
#define pread(x) printf("%d\n", x)
#define pread2(x, y) printf("%d %d\n", x, y)
#define pread3(x, y, z) printf("%d %d %d\n", x, y, z)
#define preadll(x) printf("%lld\n", x)
#define preadll2(x, y) printf("%lld %lld\n", x, y)
#define preadll3(x, y, z) printf("%lld %lld %lld\n", x, y, z)
#define preadstr(x) printf("%s\n", x)

#define MAX_PRIME 1000000
#define MAX_N 1000000
#define MOD 100000007
#define eps 1e-10
#define pi acos(-1.0)

#define readarr(a, n) rep(i, n) read(a[i])
#define printarr(a, n) rep(i, n) print(a[i]); println("")
#define preadarr(a, n) rep(i, n) pread(a[i])
#define preadarr2(a, n) rep(i, n) {pread(a[i].first); pread(a[i].second);}

#define vi vector<int>
#define vii vector< vector<int> >
#define pii pair<int, int>
#define vpii vector< pair<int, int> >
#define mii map<int, int>
#define msi map<string, int>
#define endl '\n'

const double PI = acos(-1.0);
const double EPS = 1e-10;

#define MAXN 1000000
#define MOD 100000007

typedef long long ll;
typedef unsigned long long...