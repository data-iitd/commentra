#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <functional>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr, a, b) for(int z = (a); z <= (b); z++) cout << (arr[z]) << " "; cout << endl;
#define ln cout << endl;
#define sz(x) (int)(x.size())
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) int x; cin >> x; while(x--)

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

int main() {
    fastIO;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> balls(N, vector<int>(2));
    balls[0][0] = 0;
    balls[0][1] = 1;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (balls[x][0] > 0 && balls[x][1] > 0) {
            balls[x][0]--;
            balls[y][1]++;
        } else if (balls[x][0] == 0) {
            balls[x][1]--;
            balls[y][1]++;
        } else {
            balls[x][0]--;
            balls[y][0]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1] > 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
