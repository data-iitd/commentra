#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <sstream>
#include <unordered_set>
#include <stack>
#include <deque>
#include <cassert>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vpii> vvpii;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define trav(a, x) for (auto &a : x)
#define endl '\n'

void solution() {
    string line;
    getline(cin, line);
    unordered_map<char, int> bought_count;
    for (char c : line) {
        bought_count[c]++;
    }
    getline(cin, line);
    unordered_map<char, int> made_cout;
    for (char c : line) {
        made_cout[c]++;
    }
    int res = 0;
    for (auto &p : made_cout) {
        char color = p.first;
        if (bought_count.find(color) == bought_count.end()) {
            cout << -1 << endl;
            return;
        }
        res += min(bought_count[color], p.second);
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solution();
    }
    return 0;
}
