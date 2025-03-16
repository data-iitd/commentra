#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <ctime>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define ALL(v) v.begin(), v.end()
#define SIZE(v) ((int)v.size())
#define MAX(v) (*max_element(v.begin(), v.end()))
#define MIN(v) (*min_element(v.begin(), v.end()))
#define PB push_back
#define MP make_pair
#define F first
#define S second

const int INF = INT_MAX;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    unordered_map<char, int> a;
    for (char c : s) {
        a[c]++;
    }

    int ans = 2 * (*min_element(a.begin(), a.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second < p2.second;
    })).second;

    cout << ans << endl;

    return 0;
}
