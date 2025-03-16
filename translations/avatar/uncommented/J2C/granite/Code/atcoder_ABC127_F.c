
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <queue>
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vs vector<string>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvii vector<vii>
#define vvll vector<vll>
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define F0R(i,a) for (int i = 0; i < (a); i++)
#define ROF(i,a,b) for (int i = (b); i >= (a); i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a: x)
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
#define tern(a,b,c) ((a)?(b):(c))
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#defineSZ(x) ((int)(x).size())
#define UNIQUE(v) v.resize(distance(v.begin(),unique(all(v))))
#define sortall(x) sort(all(x))
#define SQ(x) ((x)*(x))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define unsyncIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int main() {
    unsyncIO;
    int t;
    cin >> t;
    string s;
    ll sum = 0;
    priority_queue<int> pq1, pq2;
    while (t--) {
        cin >> s;
        if (s == "1") {
            int x;
            ll y;
            cin >> x >> y;
            sum += y;
            if (x >= pq1.top()) {
                pq1.push(x);
                sum -= x;
                if (pq1.size() > pq2.size() + 1) {
                    int tmp = pq1.top();
                    pq1.pop();
                    pq2.push(tmp);
                    sum += tmp;
                }
            } else {
                pq2.push(x);
                sum -= x;
                if (pq1.size() < pq2.size()) {
                    int tmp = pq2.top();
                    pq2.pop();
                    pq1.push(tmp);
                    sum += tmp;
                }
            }
        } else {
            cout << pq1.top() << " " << sum - pq1.top() * pq1.size() << endl;
        }
    }
    return 0;
}
//END-OF-CODE