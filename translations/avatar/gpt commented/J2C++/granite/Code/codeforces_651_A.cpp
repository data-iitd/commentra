
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORD(i,a,b) for (int i = (a); i > (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPD(i,n) FORD(i,n,0)
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i!= t.end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define CLR(a,b) memset(a,b,sizeof(a))
#define pb push_back

#define MP make_pair
#define PB push_back
#define S second
#define F first

const double EPS = 1e-10;
const double PI = acos(-1.0);

const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};

int MOD = 100000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    int c = 0;

    if (a == 1 && b == 1) {
        cout << 0 << endl;
    } else {
        while (a >= 1 || b >= 1) {
            if (a >= b) {
                b++;
                a -= 2;
            } else {
                a++;
                b -= 2;
            }
            if (a <= 0 || b <= 0) {
                c++;
                break;
            }
            c++;
        }
        cout << c << endl;
    }

    return 0;
}

